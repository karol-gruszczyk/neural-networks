#include "BackPropagationLearning.h"


BackPropagationLearning::BackPropagationLearning(NeuralNet& network, double learningRate, double momentum) : TrainingAlgorithm(network)
{
	this->learningRate = learningRate;
	this->momentum = momentum;
}

BackPropagationLearning::~BackPropagationLearning()
{

}

void BackPropagationLearning::backPropagate(std::vector<double> &targetVals)
{
	calculateRMSError(targetVals);
	updateGradients(targetVals);
	updateConnectionWeights();
}

void BackPropagationLearning::calculateRMSError(vector<double> &targetVals)
{
	double error = 0.0;
	for (unsigned i = 0; i < getNeuronLayers().back()->neurons.size(); ++i)
	{
		double delta = targetVals[i] - getNeuronLayers().back()->neurons[i]->outputValue;
		error = delta * delta;
	}
	error = sqrt(error / getNeuronLayers().back()->neurons.size());
}

void BackPropagationLearning::updateGradients(vector<double> &targetVals)
{
	// calculate gradients on output layer
	for (unsigned i = 0; i < getNeuronLayers().back()->neurons.size(); ++i)
	{
		auto& neuron = *getNeuronLayers().back()->neurons[i];
		neuron.gradient = (targetVals[i] - neuron.outputValue) * Neuron::activationFunctionDerivative(neuron.outputValue);
	}

	// calculate gradients on hidden layers
	for (unsigned i = getNeuronLayers().size() - 2; i > 0; --i)		
	{
		for (auto &neuron : getNeuronLayers()[i]->neurons)
		{
			double sumDOW = 0.0;
			for (auto &conn : neuron->forwardConnections)
				sumDOW += conn->weight * conn->endNeuron->gradient;
			neuron->gradient = sumDOW * Neuron::activationFunctionDerivative(neuron->outputValue);
		}
	}
}

void BackPropagationLearning::updateConnectionWeights()
{
	for (unsigned i = getNeuronLayers().size() - 1; i > 0; --i)
	{
		for (auto &neuron : getNeuronLayers()[i]->neurons)
		{
			for (auto &conn : neuron->backwardConnections)
			{
				double oldDeltaWeight = conn->deltaWeight;
				double newDeltaWeight = learningRate * neuron->gradient * conn->startNeuron->outputValue + momentum * oldDeltaWeight;

				conn->deltaWeight = newDeltaWeight;
				conn->weight += newDeltaWeight;
			}
		}
	}
}

void BackPropagationLearning::runEpoch()
{
	for (unsigned i = 0; i < inputVals.size(); i++)
	{
		network->feedForward(inputVals[i]);
		backPropagate(targetVals[i]);
	}
}
