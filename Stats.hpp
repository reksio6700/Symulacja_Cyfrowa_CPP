#pragma once

#include <iostream>
#include <random>
#include <fstream>
#include <assert.h>

extern int ALPHA;
extern int DELTA;
extern int TTT;
extern int MAXUSERS;
extern double LAMBDA;

extern long int CLOCK;

extern bool DEBUG;
extern bool WRITEFILE;

class Statistics
{
	public:
		Statistics();
		~Statistics();
};
