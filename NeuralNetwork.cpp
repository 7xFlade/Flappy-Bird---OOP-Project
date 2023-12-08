#include "NeuralNetwork.hpp"
#include <SDL.h>

// Default constructor for the NeuralNetwork class
NeuralNetwork::NeuralNetwork()
{
    threshold = 0;       // Initialize threshold to 0
    subDivisor = 800;    // Initialize subDivisor to 800
    probability = 7;     // Initialize probability to 7
}

// Function to set input values for the neural network's input layer
// Parameters:
//   birdY: Y-coordinate of the bird in the game
//   CheckPointY: Y-coordinate of the checkpoint in the game
void NeuralNetwork::InputLayer(int birdY, int CheckPointY)
{
    InputNeuron1.value = birdY;       // Set the value of the first input neuron to the bird's Y-coordinate
    InputNeuron2.value = CheckPointY; // Set the value of the second input neuron to the checkpoint's Y-coordinate
    threshold = CheckPointY;          // Update the threshold based on the checkpoint's Y-coordinate
}

// Function to update the neural network based on inputs
// Parameters:
//   birdY: Y-coordinate of the bird in the game
//   CheckPointY: Y-coordinate of the checkpoint in the game
void NeuralNetwork::Update(int birdY, int CheckPointY)
{
    InputLayer(birdY, CheckPointY);   // Call the InputLayer function to set input values
}

// Destructor for the NeuralNetwork class
NeuralNetwork::~NeuralNetwork()
{
    threshold = 0;       // Reset threshold to 0 in the destructor
    subDivisor = 0;      // Reset subDivisor to 0 in the destructor
    probability = 0;     // Reset probability to 0 in the destructor
}
