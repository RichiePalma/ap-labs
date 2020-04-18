all:
	gcc -c logger.c -o logger.o
	gcc -c testLogger.c -o testLogger.o
	gcc logger.o testLogger.o -o logger
	rm -rf logger.o testLogger.o

clean:
	rm -rf logger

include ../../common.mk
