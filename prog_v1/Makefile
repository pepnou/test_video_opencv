all: creation_vid
	

creation_vid: creation_vid.o Circle.o
	g++ creation_vid.o Circle.o -o creation_vid `pkg-config --cflags --libs opencv` -lm
	

creation_vid.o: creation_vid.cpp
	g++ -c creation_vid.cpp -o creation_vid.o `pkg-config --cflags --libs opencv`
	

Circle.o: Circle.cpp
	g++ -c Circle.cpp -o Circle.o `pkg-config --cflags --libs opencv` -lm
	


