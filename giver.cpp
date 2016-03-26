#include "giver.h"

extern Bank bank;

Giver:: Giver(string n ): name(n) {};

void Giver::addToList(int i){
	poors.push_back(i);
}

void* Giver:: help(){
	for(int I=0;I<900;I++){
		for(int i=0; i<poors.size(); i++) {
			sem_wait( & ( B(i).getSemWrite() ) );
			// begin critical
			int money = B(i).getMoney();
			string poor = B(i).getName();
			if(money<1000){
				B(i).setMoney(money+10);	
				file_format_write(STDOUT,"giver ^ %s ^ helped to ^ %s ^ and account has %d . ",name.c_str(), poor.c_str(), money+10 );
			}
			// end critical
			sem_post( & (B(i).getSemRead() ) );
		}
	}
}

