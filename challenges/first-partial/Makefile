all:
	go build -o directory-scanner dir-scan.go 
	gcc pacman-analyzer.c -o pacman-analyzer

go:
	go build -o directory-scanner dir-scan.go

c:
	gcc pacman-analyzer.c -o pacman-analyzer

clean:
	rm -rf directory-scanner
	rm -rf pacman-analyzer
	rm -rf packages_report.txt

rm-go: 
	rm -rf directory-scanner

rm-c:
	rm -rf pacman-analyzer
	rm -rf packages_report.txt
	
include ../../common.mk
