#include "Queue.hpp"

std::random_device rd3;
std::mt19937 gen3(rd3());
std::exponential_distribution<> exponential(LAMBDA);

Queue::Queue()
{
}

Queue::~Queue()
{
}
