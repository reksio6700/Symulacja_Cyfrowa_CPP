#include "Stats.hpp"

class User
{
	private:
		double powerToBS1;
		double powerToBS2;
		int velocity;
		double distance;
		int TimeToSwitch; //TTT
		short int currentBTS;

		long int currentTime; //Clock

	public:
		User();
		User(int newVelocity, int time);
		~User();

		void setBS1(int power);
		void setBS2(int power);
		void setVelocity(int v);
		void setDistance(int d);
		void setTTT(int TTT);
		void setCurrentBTS(int BTS);
		void setCurrentTime(long int time);

		double getBS1();
		double getBS2();
		int getVelocity();
		double getDistance();
		int getTTT();
		short int getBTS();
		long int getCurrentTime();
};