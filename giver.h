#ifndef __GIVER__
#define __GIVER__

#include <semaphore.h>
#include <string>
#include <vector>
#include "libioutils/io.h"
#include "bank.h"
#define B(X) bank.accounts[poors[X]]

class Giver{
private:
	vector<int> poors;
	string name;
public:
	Giver(string);
	void* help();
	void addToList(int);
	
	static void* sendFunc(void *con){
		return ((Giver*)con)->help();
	}

};

#endif
