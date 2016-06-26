# the compiler to use
CC = g++
# the compiler flags
CFLAGS = -Wall -O3 --std=c++11
# the linker flags
LFLAGS = -Wall


# objects
Math.o: Math.h  Math.ipp
	$(CC) $(CFLAGS) -c Math.cpp

Utils.o: Utils.h
	$(CC) $(CFLAGS) -c Utils.cpp

Magnet.o: Math.o  Utils.o Magnet.h  Magnet.ipp  Magnet.cpp
	$(CC) $(CFLAGS) -c Magnet.cpp

# executables
MathTest: math.t.x.cpp Math.o Test.h
	$(CC) $(CFLAGS) math.t.x.cpp -o math.t.x Math.o

UtilsTest:  utils.t.x.cpp Utils.o Test.h
	$(CC) $(CFLAGS) utils.t.x.cpp -o utils.t.x Utils.o

MagnetTest: magnet.t.x.cpp Magnet.o Test.h
	$(CC) $(CFLAGS) magnet.t.x.cpp -o magnet.t.x Magnet.o Math.o Utils.o

Tests:  MathTest UtilsTest MagnetTest
