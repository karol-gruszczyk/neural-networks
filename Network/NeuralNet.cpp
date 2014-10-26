#include "NeuralNet.h"

NeuralNet::NeuralNet(vector<unsigned> &topology, bool useBiasNeurons /*= true*/)
{
	srand((unsigned)time(NULL));

	for (auto &i : topology)
		neuronLayers.push_back(new Layer(i));

	for (unsigned i = 0; i < neuronLayers.size() - 1; ++i)
		neuronLayers[i]->createConnections(*neuronLayers[i + 1], useBiasNeurons);
}

NeuralNet::~NeuralNet()
{
	for (auto &layer : neuronLayers)
		delete layer;
}

void NeuralNet::feedForward(std::vector<double> &inputVals)
{
	if (inputVals.size() != neuronLayers.front()->neurons.size())
		throw invalid_argument("The size of the argument does not match with the number of input neurons!");

	for (unsigned i = 0; i < inputVals.size(); ++i)
		neuronLayers.front()->neurons[i]->outputValue = inputVals[i];

	for (unsigned i = 1; i < neuronLayers.size(); ++i)
		for (unsigned j = 0; j < neuronLayers[i]->neurons.size(); ++j)
			neuronLayers[i]->neurons[j]->feedForward();
}

vector<double> NeuralNet::getResults()
{
	vector<double> resultVals;
	for (auto &outNeuron : neuronLayers.back()->neurons)
		resultVals.push_back(outNeuron->outputValue);
	return resultVals;
}

void NeuralNet::printNeuralNet()
{
	for (auto &layer : neuronLayers)
	{
		for (auto &neuron : layer->neurons)
		{
			cout << "(o: " << neuron->outputValue << ", g: " << neuron->gradient << ")";
		}
		cout << "({B}o: " << layer->biasNeuron.outputValue << ", g: " << layer->biasNeuron.gradient << ")" << endl;
	}
}