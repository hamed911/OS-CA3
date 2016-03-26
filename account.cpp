#include "account.h"

Account::Account(int Money, string Name, string Phone){
	money = Money;
	name = Name;
	phone = Phone;
	go=0;
	done=0;
	sem_init(&read,0,0);
	sem_init(&write,0,0);
	sem_init(&mu1,0,1);
	sem_init(&mu2,0,0);
}

string Account::getName(){
	return name;
}

string Account::getPhone(){
	return phone;
}

int Account::getMoney(){
	return money;
}

void Account::setMoney(int newMoney){
	money = newMoney;
}

sem_t& Account::getSemRead(){
	return read;
}

sem_t& Account::getSemWrite(){
	return write;
}

sem_t& Account::getSemMu1(){
	return mu1;
}

sem_t& Account::getSemMu2(){
	return mu2;
}
