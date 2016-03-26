#ifndef __ACCOUNT__
#define __ACCOUNT__
#include <string>
#include <semaphore.h>

using namespace std;

class Account{
private:
	int money;
	string name;
	string phone;

	sem_t read;
	sem_t write;
	sem_t mu1;
	sem_t mu2;
	int go;
	int done;

public:
	Account(int,string,string);
	string getName();
	string getPhone();
	int getMoney();
	void setMoney(int);
	sem_t& getSemRead();
	sem_t& getSemWrite();
	sem_t& getSemMu1();
	sem_t& getSemMu2();
	void incGo(){ go++; }
	void incDone(){ done++; }
	void resGo() { go = 0; }
	void resDone() { done = 0; }
	int getGo() { return go; }
	int getDone() { return done; }
};

#endif
