#include "Queue.hpp"

std::random_device rd3;
std::mt19937 gen3(rd3());
std::exponential_distribution<> exponential(LAMBDA);

Queue::Queue()
{
	this->maxSize = MAXUSERS;
}

Queue::Queue(int size)
{
	this->maxSize = size;
}

Queue::~Queue()
{
}

bool Queue::push(User* u)
{
	if (this->fifo.size() >= this->maxSize) return false;
	this->fifo.push(u);
	return true;
}

User* Queue::pop()
{
	if(this->fifo.empty()) return nullptr;
	//User* temp = this->fifo.front();
	User* temp = this->fifo.top();
	this->fifo.pop();
	return temp;
}

int Queue::size()
{
	return this->fifo.size();
}

bool Queue::isFull()
{
	if(this->fifo.size() == this->maxSize) return true;
	return false;
}
