#pragma once

// Neuron class representing a basic unit in a neural network
class Neuron
{
private:
    double value; // Value associated with the neuron

public:
    // Default constructor for the Neuron class
    Neuron();

    // Destructor for the Neuron class
    ~Neuron();

    // Setter function to set the value of the neuron
    // Parameters:
    //   val: The value to set for the neuron
    void setValue(double val);

    // Friend class declaration for NeuralNetwork to allow access to private members
    friend class NeuralNetwork;
};
