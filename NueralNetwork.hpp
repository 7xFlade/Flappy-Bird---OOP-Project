#pragma once
#include "Neuron.hpp"

// NeuralNetwork class representing a simple neural network with two input neurons
class NeuralNetwork
{
private:
    int threshold;        // Threshold for network activation
    int subDivisor;       // Subdivisor used in calculations
    int probability;      // Probability value used in calculations
    Neuron InputNeuron1;  // First input neuron
    Neuron InputNeuron2;  // Second input neuron

public:
    // Default constructor for the NeuralNetwork class
    NeuralNetwork();

    // Destructor for the NeuralNetwork class
    ~NeuralNetwork();

    // Function to handle the input layer of the neural network
    // Parameters:
    //   birdY: Y-coordinate of the bird in the game
    //   CheckPointY: Y-coordinate of the checkpoint in the game
    void InputLayer(int birdY, int CheckPointY);

    // Function to update the neural network based on inputs
    // Parameters:
    //   birdY: Y-coordinate of the bird in the game
    //   CheckPointY: Y-coordinate of the checkpoint in the game
    void Update(int birdY, int CheckPointY);
};
