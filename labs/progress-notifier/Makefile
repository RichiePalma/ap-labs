all:
	gcc -c base64.c -o b64 
	gcc -c logger.c -o logger
	gcc b64 logger -o base64
	rm -rf b64 logger

clean:
	rm -rf base64 encoded.txt decoded.txt

include ../../common.mk
