#include <iostream>

#include "Network/NeuralNet.h"
#include "Network/BackPropagationLearning.h"

using namespace std;

int main()
{
	NeuralNet net = vector<unsigned>{ 2, 2, 1 };
	BackPropagationLearning teacher = { net, 0.01, 0.01 };

	teacher.addSample({ 0.0, 0.0 }, { 0.0 });
	teacher.addSample({ 1.0, 1.0 }, { 0.0 });
	teacher.addSample({ 1.0, 0.0 }, { 1.0 });
	teacher.addSample({ 0.0, 1.0 }, { 1.0 });

	

	for (auto i = 0; i < 20000; i++)
	{
		teacher.runEpoch();
	}
	net.feedForward(vector<double>{0, 0});
	cout << net.getResults()[0] << endl;
	net.feedForward(vector<double>{1, 1});
	cout << net.getResults()[0] << endl;
	net.feedForward(vector<double>{0, 1});
	cout << net.getResults()[0] << endl;
	net.feedForward(vector<double>{1, 0});
	cout << net.getResults()[0] << endl;
	system("pause");
	return 1;
}