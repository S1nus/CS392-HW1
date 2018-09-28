#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "wrong number of command line arguments\n");
		return(-1);
	}

	FILE* toRead;
	FILE* toWrite;

	const char tab = '\t';

	toRead = fopen(argv[1], "r"); 
	toWrite = fopen(argv[2], "wb");

	unsigned short uid;
	fread(&uid, sizeof(uid), 1, toRead);
	fprintf(toWrite, "%hu", uid);
}
