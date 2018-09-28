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
	
	while (!feof(toRead)) {
		unsigned short uid;
		fread(&uid, sizeof(uid), 1, toRead);
		fprintf(toWrite, "%hu", uid);
		fprintf(toWrite, "%c", tab);
		
		unsigned short iid;
		fread(&iid, sizeof(iid), 1, toRead);
		fprintf(toWrite, "%hu", iid);
		fprintf(toWrite, "%c", tab);

		unsigned char rating;
		fread(&rating, sizeof(rating), 1, toRead);
		//fgets(&rating, sizeof(rating), toRead);
		fprintf(toWrite, "%u", rating);
		fprintf(toWrite, "%c", tab);
		
		unsigned long timestamp;
		fread(&timestamp, sizeof(timestamp), 1, toRead);
		fprintf(toWrite, "%lu", timestamp);
		fprintf(toWrite, "%c", '\n');
	}
}
