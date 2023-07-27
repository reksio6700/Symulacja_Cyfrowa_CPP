#include "Queue.hpp"

class Simulator
{
	private:
		Statistics stats;
		Queue queue;

	public:
		Simulator();
		~Simulator();

		void run();
};