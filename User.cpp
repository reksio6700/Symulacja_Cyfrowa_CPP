#include "User.hpp"
#include "Stats.hpp"

User::User()
{
	this->powerToBS1 = 0;
	this->powerToBS2 = 0;
	this->velocity = 0;
	this->distance = 0;
	this->TimeToSwitch = 0;
	this->currentBTS = 0;
	this->currentTime = 0;
}

User::User(int newVelocity, int time)
{
	this->powerToBS1 = -70.0;
	this->powerToBS2 = -70.0;
	this->velocity = newVelocity;
	this->distance = 2000.0;
	this->TimeToSwitch = 0;
	this->currentBTS = 1;
	this->currentTime = time;
}

User::~User()
{
}

void User::setBS1(int power)
{
	this->powerToBS1 = power;
}

void User::setBS2(int power)
{
	this->powerToBS2 = power;
}

void User::setVelocity(int v)
{
	this->velocity = v;
}

void User::setDistance(int d)
{
	this->distance = d;
}

void User::setTTT(int TTT)
{
	this->TimeToSwitch = TTT;
}

void User::setCurrentBTS(int BTS)
{
	assert(BTS >= 1 && BTS <= 2); //BTS must be 1 or 2
	this->currentBTS = BTS;
}

void User::setCurrentTime(long int time)
{
	assert(time >= CLOCK); //Time must be bigger than sim's clock
	this->currentTime = time;
}

double User::getBS1()
{
	return this->powerToBS1;
}

double User::getBS2()
{
	return this->powerToBS2;
}

int User::getVelocity()
{
	return this->velocity;
}

double User::getDistance()
{
	return this->distance;
}

int User::getTTT()
{
	return this->TimeToSwitch;
}

short int User::getBTS()
{
	return this->currentBTS;
}

long int User::getCurrentTime()
{
	return this->currentTime;
}
