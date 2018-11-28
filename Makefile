all: compil
	./creation_im
	

compil:
	g++ creation_im.cpp -o creation_im `pkg-config --cflags --libs opencv`
