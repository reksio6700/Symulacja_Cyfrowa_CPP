#pragma once

#include <iostream>
#include <math.h>
#include <random>
#include <fstream>
#include <assert.h>

extern int ALPHA; //Switch threshold
extern int DELTA; //Drop treshold
extern int TTT; //ms to BS switch (20 ms equals 1 report)
extern int MAXUSERS; //Active queue size limit
extern double LAMBDA; //Traffic generation intensity

extern long int CLOCK; //Main simulator clock

extern bool DEBUG; //Print debug info
extern bool WRITEFILE; //Write stats to text file

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
