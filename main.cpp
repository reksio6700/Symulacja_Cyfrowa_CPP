#include "Simulator.hpp"

int main()
{
	ALPHA = 3;
	DELTA = 20;
	TTT = 20;
	MAXUSERS = 40;
	LAMBDA = 0.1;
	CLOCK = 0;

	Simulator simulator;

	Queue q;
	User* u = new User(5);
	q.push(u);
	printf("%d\n", q.size());
	User* u2 = nullptr;
	u2 = q.pop();
	printf("%d\n", u2->getVelocity());
	printf("%d\n", q.size());
	delete u;

	return 0;
}
