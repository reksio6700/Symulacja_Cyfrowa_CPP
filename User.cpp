#include "User.hpp"
#include "Stats.hpp"

std::random_device rd;
std::mt19937 gen(rd());
std::random_device rd2;
std::mt19937 gen2(rd2());
std::uniform_int_distribution<> uniform(5, 50);
std::normal_distribution<> normal(0, 4);

User::User()
{
	this->powerToBS1 = 0;
	this->powerToBS2 = 0;
	this->velocity = 0;
	this->distance = 0;
	this->TimeToSwitch = 0;
	this->currentBTS = 0;
}

User::User(int newVelocity)
{
	this->powerToBS1 = -70.0;
	this->powerToBS2 = -70.0;
	this->velocity = newVelocity;
	this->distance = 2000.0;
	this->TimeToSwitch = 0;
	this->currentBTS = 1;
}

User::~User()
{
}
