#ifndef TRAINING_ALGORITHM_H
#define  TRAINING_ALGORITHM_H

#include <vector>

#include "NeuralNet.h"

using namespace std;

class TrainingAlgorithm
{
public:
	TrainingAlgorithm(NeuralNet& network);
	virtual ~TrainingAlgorithm();

	void addSample(vector<double> inputVals, vector<double> outputVals);
	//void setTrainingData
	void runEpoch();
protected:
	NeuralNet* network;
	vector<vector<double>> inputVals;
	vector<vector<double>> targetVals;

	vector<Layer*>& getNeuronLayers() { return network->neuronLayers; };
};

#endif
