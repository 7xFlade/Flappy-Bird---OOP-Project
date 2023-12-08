#pragma once

class Neuron
{
private:
	double value;
public:
	Neuron();
	~Neuron();
	void setValue(double val);
	friend class NeuralNetwork;
};
