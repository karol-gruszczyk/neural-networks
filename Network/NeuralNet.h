#ifndef NEURAL_NET_H
#define NEURAL_NET_H

#include <vector>
#include <stdexcept>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include "Layer.h"


using namespace std;

class NeuralNet
{
	friend class TrainingAlgorithm;
public:
	NeuralNet(vector<unsigned> &topology, bool useBiasNeurons = true);
	~NeuralNet();
	void feedForward(vector<double> &inputVals);
	vector<double> getResults();

	void printNeuralNet();
private:
	vector <Layer*> neuronLayers;
};

#endif
