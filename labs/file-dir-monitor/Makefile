all:
	gcc -c monitor.c -o mon
	gcc -c logger.c -o logger
	gcc mon logger -o monitor
	rm -rf mon logger
clean:
	rm -rf monitor

include ../../common.mk
