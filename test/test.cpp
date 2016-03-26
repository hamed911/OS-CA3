#include <pthread.h>
#include <iostream>
using namespace std;

class tt{
public:
	pthread_t p;
	int j;
	tt(int I){
		j=I;
		pthread_create(&p, NULL, &tt::sendFunc , this);
	}

	void* doing(){
		for(int i=0;i<999999;i++)
			cout<<j<<": sina GOL.\n";
	}

	static void *sendFunc(void *con){
		return ((tt*)con)->doing();
	}
};

int main(){
	tt t1(2);
	tt t2(3);
	while(true);
}
