#include "Simulator.hpp"

Simulator::Simulator()
{
	this->stats.clearStats();
}

Simulator::~Simulator()
{
}

int Simulator::run()
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
	if (DEBUG) printf("Pushing first user manually\n");
	this->stats.incTotal();
	this->stats.incActive();
	/*
	* Creating text file for statistics write
	*/
	std::fstream statsOutput;
	statsOutput.open("stats.txt", std::ios::out);
	if (!(statsOutput.is_open() && statsOutput.good())) return -1;
	statsOutput << "CLOCK\t" << "TOTAL\t" << "ACTIVE\t" << "QUEUE\t" << "SERVED\t" << "DROPPED\t" << "SWITCH\n";

	while(this->stats.getServed() < stop)
	{
		//Get first user from fifo
		currentUser = this->queue.pop();
		if(DEBUG) printf("%d\t%d\n", this->queue.size(), currentUser->getCurrentTime());

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

			//Compute distance
			currentUser->setDistance(currentUser->getDistance() + (currentUser->getVelocity() / 50));
			//Compute powers
			currentUser->setBS1(4.56 - 22 * log10(currentUser->getDistance()) + normal(gen2));
			currentUser->setBS2(4.56 - 22 * log10(5000.0 - currentUser->getDistance()) + normal(gen2));

			//Time to trigger if power difference exceeds threshold
			if (abs(currentUser->getBS1() - currentUser->getBS2()) > ALPHA)
			{
				currentUser->incTTT();
				if (currentUser->getTTT() >= TTT)
				{
					if (currentUser->getBTS() == 1) currentUser->setCurrentBTS(2);
					else currentUser->setCurrentBTS(1);
					currentUser->setTTT(0);
					this->stats.incSwitch();
					if (DEBUG) printf("User switched to BTS %d\n", currentUser->getBTS());
				}
			}

			//Drop user if power difference exceeds threshold or 3km reached
			if (abs(currentUser->getBS1() - currentUser->getBS2()) > DELTA)
			{
				this->stats.incDropped();
				this->stats.decActive();
				delete currentUser;
				currentUser = nullptr;
				if (DEBUG) printf("Dropping user from queue - DELTA\n");
			}
			else if (currentUser->getDistance() > 3000.0)
			{
				this->stats.incServed();
				this->stats.decActive();
				delete currentUser;
				currentUser = nullptr;
				if (DEBUG) printf("Dropping user from queue - DISTANCE\n");
			}
		}
		
		//Push new users if possible
		if (newUsersCounter > 0)
		{
			while( (this->queue.size() + 1) < MAXUSERS && newUsersCounter > 0)
			{
				this->queue.push(new User(uniform(gen), CLOCK + 1));
				newUsersCounter--;

				this->stats.decQueue();
				this->stats.incActive();
				if (DEBUG) printf("Pushing new user to queue\n");
			}
		}

		//

		//Push user back if not served or dropped
		if (currentUser != nullptr)
		{
			currentUser->setCurrentTime(currentUser->getCurrentTime() + 20);
			this->queue.push(currentUser);
		}

		//Write statistics to text file
		if (WRITEFILE)
		{
			statsOutput << CLOCK << "\t" <<
				this->stats.getTotal() << "\t" <<
				//this->stats.getActive() << "\t" <<
				this->queue.size() << "\t" <<
				//this->stats.getQueue() << "\t" <<
				newUsersCounter << "\t" <<
				this->stats.getServed() << "\t" <<
				this->stats.getDropped() << "\t" <<
				this->stats.getSwitch() << "\n";
		}
	}
	statsOutput.close();
	return 0;
}
