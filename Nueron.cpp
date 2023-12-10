#include "Nueron.hpp"

Neuron::Neuron()
{
	value = 0;
}

void Neuron::setValue(double val)
{
	this->value = val;
}

Neuron::~Neuron()
{
	value = 0;
}
