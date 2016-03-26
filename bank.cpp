#include "bank.h"

void* userSMS(void*);

void Bank::addAccount(int money, string name, string phone){
	accounts.push_back(Account(money, name, phone));
	sem_t* newSMSR = new sem_t;
	sem_t* newSMSW = new sem_t;
	sem_init(newSMSR, 0, 0);
	sem_init(newSMSW, 0, 1);
	phoneToSem[phone] = make_pair(newSMSR,newSMSW);
	pthread_t user;
	int* id = new int;
	*id = accounts.size()-1;
	cout<<"Account "<<name<<" has created.\n";
	pthread_create(&user, NULL, userSMS, (void*)id);
}

void Bank::toAccount(int id, int money){
	sem_wait(phoneToSem[accounts[id].getPhone()].second);
	accounts[id].setMoney(accounts[id].getMoney()+money);
	sem_post(phoneToSem[accounts[id].getPhone()].first);
}
