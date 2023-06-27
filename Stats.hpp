#pragma once

#include <iostream>
#include <random>
#include <fstream>

extern int ALPHA;
extern int DELTA;
extern int TTT;
extern int MAXUSERS;
extern double LAMBDA;

extern bool DEBUG;
extern bool WRITEFILE;

class Statistics
{
	public:
		Statistics();
		~Statistics();
};
