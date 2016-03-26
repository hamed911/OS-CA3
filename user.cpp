#include "user.h"

extern Bank bank;
extern sem_t coutSem;

void* userSMS(void* Id){
	int id = *((int*)Id);
	delete Id;
	int money = bank.accounts[id].getMoney();
	cout<<"Thread for "<<bank.accounts[id].getName()<<" has created.\n";
	while (true){
		sem_wait(bank.phoneToSem[bank.accounts[id].getPhone()].first);
		file_format_write(STDOUT,"%s: \"My money changed from %d to %d\".\n",bank.accounts[id].getName().c_str(),money,bank.accounts[id].getMoney());
		money = bank.accounts[id].getMoney(); 
		sem_post(bank.phoneToSem[bank.accounts[id].getPhone()].second);
	}
}
