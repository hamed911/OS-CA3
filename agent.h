#ifndef __AGENT__
#define __AGENT__

#include <semaphore.h>
#include <string>
#include "libioutils/io.h"
#include "bank.h"
#define B(X) bank.accounts[wanted[X]]
using namespace std;

class Agent{
private:
	vector<int> wanted;
	int fd;
	string name;
public:
	Agent(string);
	void* read();
	void addToList(int i);	
	static void* sendFunc(void* con){
		return ((Agent*)con)->read();
	}
};

#endif
