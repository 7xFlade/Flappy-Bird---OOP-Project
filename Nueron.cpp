#include "Neuron.hpp"

// Default constructor for the Neuron class
Neuron::Neuron()
{
    value = 0; // Initialize the value to 0
}

// Setter function to set the value of the neuron
// Parameters:
//   val: The value to set for the neuron
void Neuron::setValue(double val)
{
    this->value = val; // Set the value of the neuron
}

// Destructor for the Neuron class
Neuron::~Neuron()
{
    value = 0; // Reset the value to 0 in the destructor
}
