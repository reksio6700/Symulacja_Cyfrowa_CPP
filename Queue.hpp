#include "User.hpp"
#include "Stats.hpp"

#include <queue>

class Queue
{
	private:
		int maxSize;
		//std::queue<User*> fifo;
		std::priority_queue<User*, std::vector<User*>, compareUser > fifo;

	public:
		Queue();
		Queue(int size);
		~Queue();

		bool push(User* u);
		User* pop();
		int size();
		bool isFull();
};