Main.out: Main.o
	g++ -o Main.out *.o -pthread ./libioutils/ioutils.a -L.
Main.o: Main.cpp bank.h bank.o agent.o giver.o
	g++ -c Main.cpp
bank.o: bank.h bank.cpp user.o account.o
	g++ -c bank.cpp
user.o: user.h user.cpp
	g++ -c user.cpp
account.o: account.h account.cpp
	g++ -c account.cpp
agent.o: agent.cpp agent.h
	g++ -c agent.cpp
giver.o: giver.cpp  giver.h
	g++ -c giver.cpp

clear:
	rm *.o Main.out
