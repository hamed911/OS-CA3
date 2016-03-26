#ifndef __BANK__
#define __BANK__
#include "account.h"
#include <map>
#include <vector>
#include <pthread.h>
#include <iostream>
#include <semaphore.h>
using namespace std;

class Bank{
public:
	vector<Account> accounts;
	map<string, pair<sem_t*,sem_t*> > phoneToSem;
	
	void addAccount(int, string, string);
	void toAccount(int, int);
};

#endif
