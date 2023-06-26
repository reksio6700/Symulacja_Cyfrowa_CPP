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
}

User::~User()
{
}
