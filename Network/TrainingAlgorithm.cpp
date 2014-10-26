#include "TrainingAlgorithm.h"


TrainingAlgorithm::TrainingAlgorithm(NeuralNet& network)
{
	this->network = &network;
}

TrainingAlgorithm::~TrainingAlgorithm()
{
}

void TrainingAlgorithm::addSample(vector<double> inputVals, vector<double> targetVals)
{
	if (inputVals.size() != network->neuronLayers.front()->neurons.size() || targetVals.size() != network->neuronLayers.back()->neurons.size())
		throw invalid_argument("The given arguments does not match the network topology!");

	this->inputVals.push_back(inputVals);
	this->targetVals.push_back(targetVals);
}
