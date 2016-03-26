#include <iostream>
#include "user.h"
#include "giver.h"
#include "agent.h"

using namespace std;

Bank bank;
sem_t coutSem;

int main(){
	sem_init(&coutSem,0,1);
	bank.addAccount(120,"hamed","+989365836059");
	bank.addAccount(99999999,"Sina","+989355282852");
	bank.toAccount(0,-10);
	bank.toAccount(1,+1000);
	bank.toAccount(0,-30);
	bank.toAccount(1,+2500);
	bank.toAccount(1,+2400);
	bank.toAccount(1,+2300);
	bank.toAccount(1,+2200);

	Giver g1("Moein");
	g1.addToList(0);
	Agent a1("Hosein");
	a1.addToList(0);
	Agent a2("Hosei");
	a2.addToList(0);
	Agent a3("Hose");
	a3.addToList(0);
	Agent a4("Hos");
	a4.addToList(0);
	Agent a5("Ho");
	a5.addToList(0);
	Agent a6("H");
	a6.addToList(0);

	
	pthread_t p1;
	pthread_t p2;
	pthread_t p3;
	pthread_t p4;
	pthread_t p5;
	pthread_t p6;
	pthread_create(&p2,NULL,&(Giver::sendFunc),&g1);
	pthread_create(&p1,NULL,&(Agent::sendFunc),&a1);
	pthread_create(&p3,NULL,&(Agent::sendFunc),&a2);
	pthread_create(&p4,NULL,&(Agent::sendFunc),&a3);
	pthread_create(&p5,NULL,&(Agent::sendFunc),&a4);
	pthread_create(&p6,NULL,&(Agent::sendFunc),&a5);

	while(true);
}
