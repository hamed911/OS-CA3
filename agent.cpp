#include "agent.h"

extern Bank bank;

Agent::Agent(string Name) : name(Name) {
	fd = get_file_descriptor(".",Name.c_str());
}

void Agent::addToList(int i){
	wanted.push_back(i);
}

void* Agent::read(){
	for(int I=0;I<100;I++){
		for(int i=0;i<wanted.size();i++){
			sem_wait(&(bank.accounts[wanted[i]].getSemMu1()));
			cerr<<(B(i).getGo())<<"\n";
			B(i).incGo();
			if(B(i).getGo()==5){
				sem_post(& (B(i).getSemMu2()) );
				sem_wait(& (B(i).getSemRead()) );
				B(i).resGo();
			}
			sem_post(& ( B(i).getSemMu1() ));
			//Critical Section Begins
			int money = bank.accounts[wanted[i]].getMoney();
			string name = bank.accounts[wanted[i]].getName();
			file_format_write(fd,"account %s is checked: %d.\n",name.c_str(),money);
			file_format_write(STDOUT,"account %s is checked: %d.\n",name.c_str(),money);
			//Critical Section Ends
			sem_wait(& (B(i).getSemMu2()) );
			B(i).incDone();
			if( B(i).getDone() ==4){
				sem_post( & B(i).getSemWrite() );
				B(i).resDone();
			}
			sem_post(& B(i).getSemMu2() );
		}
	}
}

