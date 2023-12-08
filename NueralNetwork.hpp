#pragma once
#include"Nueron.hpp"

class NeuralNetwork
{
private:
	int threshold;
	int subDivisor;
	int probablity;
	Neuron InputNeuron1;
	Neuron InputNeuron2;
public:
	NeuralNetwork();
	~NeuralNetwork();
	void InputLayer(int birdY, int CheckPointY);
	void Update(int birdY, int CheckPointY);

};
