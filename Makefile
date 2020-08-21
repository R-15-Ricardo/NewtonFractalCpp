all: nr

nr: main.o isosurface.o hsvtorgb.o
	g++ main.o isosurface.o hsvtorgb.o -o nr -lsfml-graphics -lsfml-system -lsfml-window

main.o: main.cpp
	g++ -c main.cpp

isosurface: isosurface.cpp
	g++ -c isosurface.cpp

hsvtorgb.o: hsvtorgb.cpp
	g++ -c hsvtorgb.cpp

clean:
	rm main.o isosurface.o hsvtorgb.o nr
