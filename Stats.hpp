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
	private:
		int totalUsers;
		int activeUsers;
		int queueSize;
		int droppedUsers;
		int servedUsers;
		int switches;

	public:
		Statistics();
		~Statistics();

		void clearStats();
		void incTotal();
		void incActive();
		void decActive();
		void incQueue();
		void decQueue();
		void incServed();
		void incDropped();
		void incSwitch();

		int getTotal();
		int getActive();
		int getQueue();
		int getServed();
		int getDropped();
		int getSwitch();
};
