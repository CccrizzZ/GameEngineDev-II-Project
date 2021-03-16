#include "CommandQueue.h"

void CommandQueue::push(const Command newCommand)
{
	mQueue.push(newCommand);
}

Command CommandQueue::pop()
{
	Command temp;
	if(!isEmpty())
	{
		temp = mQueue.front();
		mQueue.pop();
		return temp;
	}
}

bool CommandQueue::isEmpty() const
{
	if (mQueue.size() > 0)
	{
		return false;
	}
	return true;
}
