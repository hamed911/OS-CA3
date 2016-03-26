ioutils.a: writer.o reader.o opener.o 
	ar -cvr -o ioutils.a reader.o writer.o opener.o
reader.o: reader.cpp
	g++ -c reader.cpp
writer.o: writer.cpp
	g++ -c writer.cpp
opener.o: opener.cpp
	g++ -c opener.cpp
clear: 
	rm *.o ioutils.a
