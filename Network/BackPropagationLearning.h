#ifndef BACK_PROPAGATION_LEARNING_H
#define BACK_PROPAGATION_LEARNING_H

#include "TrainingAlgorithm.h"
#include "Neuron.h"

class BackPropagationLearning : public TrainingAlgorithm
{
public:
	BackPropagationLearning(NeuralNet& network, double learningRate, double momentum);
	~BackPropagationLearning();

	void runEpoch();
	void runEpoch(vector<unsigned> inputVals, vector<unsigned> outputVals){}
private:
	double learningRate;
	double momentum;

	void backPropagate(std::vector<double> &targetVals);
	void calculateRMSError(vector<double> &targetVals);
	void updateGradients(vector<double> &targetVals);
	void updateConnectionWeights();

	static double activationFunction(double& value) { return tanh(value); }
	static double activationFunctionDerivative(const double x) { return 1.0 - x * x; }
};

#endif
