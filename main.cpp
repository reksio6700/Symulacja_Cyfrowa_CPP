#include "Simulator.hpp"

int main()
{
	ALPHA = 3;
	DELTA = 20;
	TTT = 20;
	MAXUSERS = 40;
	LAMBDA = 0.01;
	CLOCK = 0;

	Simulator simulator;
	simulator.run();

	return 0;
}
