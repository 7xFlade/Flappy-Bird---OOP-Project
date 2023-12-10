#include "NueralNetwork.hpp"

NeuralNetwork::NeuralNetwork()
{
	threshold = 0;

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
}

