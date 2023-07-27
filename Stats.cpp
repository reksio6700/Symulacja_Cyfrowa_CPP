#include "Stats.hpp"

int ALPHA = 3;
int DELTA = 20;
int TTT = 20;
int MAXUSERS = 40;
double LAMBDA = 0.1;

long int CLOCK = 0;

bool DEBUG = true;
bool WRITEFILE = true;

Statistics::Statistics()
{
	this->totalUsers = 0;
	this->activeUsers = 0;
	this->queueSize = 0;
	this->servedUsers = 0;
	this->droppedUsers = 0;
	this->switches = 0;
}

Statistics::~Statistics()
{
}

void Statistics::clearStats()
{
	this->totalUsers = 0;
	this->activeUsers = 0;
	this->queueSize = 0;
	this->servedUsers = 0;
	this->droppedUsers = 0;
	this->switches = 0;
}

void Statistics::incTotal()
{
	this->totalUsers++;
}

void Statistics::incActive()
{
	this->activeUsers++;
}

void Statistics::decActive()
{
	this->activeUsers--;
}

void Statistics::incQueue()
{
	this->queueSize++;
}

void Statistics::decQueue()
{
	this->queueSize--;
}

void Statistics::incServed()
{
	this->servedUsers++;
}

void Statistics::incDropped()
{
	this->droppedUsers++;
}

void Statistics::incSwitch()
{
	this->switches++;
}

int Statistics::getTotal()
{
	return this->totalUsers;
}

int Statistics::getActive()
{
	return this->activeUsers;
}

int Statistics::getQueue()
{
	return this->queueSize;
}

int Statistics::getServed()
{
	return this->servedUsers;
}

int Statistics::getDropped()
{
	return this->droppedUsers;
}

int Statistics::getSwitch()
{
	return this->switches;
}
