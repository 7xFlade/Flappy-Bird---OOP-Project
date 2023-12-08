#include "NueralNetwork.hpp"
#include <SDL.h>

NeuralNetwork::NeuralNetwork()
{
	threshold = 0;
	subDivisor = 800;
	probablity = 7;
}


void NeuralNetwork::InputLayer(int birdY, int CheckPointY)
{
	InputNeuron1.value = birdY;
	InputNeuron2.value = CheckPointY;
	threshold = CheckPointY;
}


void NeuralNetwork::Update(int birdY, int CheckPointY)
{
	InputLayer(birdY, CheckPointY);
}


NeuralNetwork::~NeuralNetwork()
{
	threshold = 0;
	subDivisor = 0;
}
