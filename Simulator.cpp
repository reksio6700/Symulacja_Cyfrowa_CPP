#include "Simulator.hpp"

Simulator::Simulator()
{
	this->stats.clearStats();
}

Simulator::~Simulator()
{
}

void Simulator::run()
{
	//RNGs
	std::random_device rd;
	std::mt19937 gen(rd());
	std::random_device rd2;
	std::mt19937 gen2(rd2());
	std::random_device rd3;
	std::mt19937 gen3(rd3());
	std::uniform_int_distribution<int> uniform(5, 50);
	std::normal_distribution<double> normal(0, 4);
	std::exponential_distribution<double> exponential(LAMBDA);

	/*
	* !!!STOP CONDITION!!!
	* Abort simulation if number of served users exceeds 'stop'.
	* Change at your own risk.
	*/
	int stop = 1000;
	/*
	* Counts number of users waiting to enter the system.
	* Computed on time difference between clock and active user's set time.
	*/
	int newUsersCounter = 0;
	/*
	* Time to generate new user.
	*/
	int newUserIn = exponential(gen3);
	/*
	* Time between current and last user.
	* Used to compute traffic intensity and generate new users..
	*/
	long int timeBetweenUsers = 0;
	/*
	* Pointer to currently handled user.
	* Removed from fifo in each iteration. If not dropped or served will be pushed back to fifo.
	*/
	User* currentUser = nullptr;
	/*
	* Adding first user manually
	*/
	this->queue.push(new User(uniform(gen), CLOCK + 0));
	this->stats.incTotal();
	this->stats.incActive();

	while(this->stats.getServed() < stop)
	{
		//Get first user from fifo
		currentUser = this->queue.pop();
		printf("%d\t%d\n", this->queue.size(), currentUser->getCurrentTime());

		if (currentUser != nullptr)
		{
			//Compute time
			timeBetweenUsers += currentUser->getCurrentTime() - CLOCK;
			CLOCK = currentUser->getCurrentTime();
			if (timeBetweenUsers > newUserIn)
			{
				timeBetweenUsers -= newUserIn;
				newUsersCounter++;
				newUserIn = exponential(gen3);

				this->stats.incTotal();
				this->stats.incQueue();
			}
		}
		
		//Push new users if possible
		if (newUsersCounter > 0)
		{
			while(!this->queue.isFull() && newUsersCounter > 0)
			{
				this->queue.push(new User(uniform(gen), CLOCK + 1));
				newUsersCounter--;

				this->stats.decQueue();
				this->stats.incActive();
			}
		}

		//

		//Push user back if not served or dropped
		if (currentUser != nullptr)
		{
			currentUser->setCurrentTime(currentUser->getCurrentTime() + 20);
			this->queue.push(currentUser);
		}
	}
}
