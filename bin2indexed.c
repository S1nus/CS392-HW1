#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findLineItem(int id, FILE* file) {
	/*char line[256];
	int lineCount = 1;
	size_t bytes = 0;
	while (fgets(line, sizeof(line), file)) {
		//printf("%s", line);
		if (lineCount = id) {
			printf("size is: \n");
			printf("%zi", bytes);
			return lineCount;
		}
		else {
			bytes += sizeof(line);
		}
		lineCount++;
	}*/
	char cc;
	int offset = 0;
	int lineCount = 0;
	while (!feof(file)) {
		cc = fgetc(file);
		offset++;
		//printf("%c", cc);
		if (cc == '\n') {
			lineCount++;
		}
		if (lineCount == id) {
			return offset;
		}
	}
}

int main(int argc, char** argv) {
	if (argc != 4) {
		fprintf(stderr, "wrong number of command line arguments\n");
		return(-1);
	}

	FILE* binToRead;
	FILE* itemToRead;
	FILE* binToWrite;

	binToRead = fopen(argv[1], "r");
	itemToRead = fopen(argv[2], "r");
	binToWrite = fopen(argv[3], "wb");

/* ====== */

	while (!feof(binToRead)) {
		unsigned short uid;
		fread(&uid, sizeof(uid), 1, binToRead);
		//fprintf(toWrite, "%hu", uid);
		//fprintf(toWrite, "%c", tab);
		
		unsigned short iid;
		fread(&iid, sizeof(iid), 1, binToRead);
		//fprintf(toWrite, "%hu", iid);
		//fprintf(toWrite, "%c", tab);

		unsigned char rating;
		fread(&rating, sizeof(rating), 1, binToRead);
		//fgets(&rating, sizeof(rating), toRead);
		//fprintf(toWrite, "%u", rating);
		//fprintf(toWrite, "%c", tab);
		
		unsigned long timestamp;
		fread(&timestamp, sizeof(timestamp), 1, binToRead);
		//fprintf(toWrite, "%lu", timestamp);
		//fprintf(toWrite, "%c", '\n');

		fwrite(&uid, sizeof(uid), 1, binToWrite);
		//fwrite(&iid, sizeof(iid), 1, binToWrite);
		unsigned int offset = findLineItem(iid, itemToRead);
		fwrite(&offset, sizeof(offset), 1, binToWrite);
		fwrite(&rating, sizeof(rating), 1, binToWrite);
		fwrite(&timestamp, sizeof(timestamp), 1, binToWrite);
	}

/* ====== */


	fclose(binToRead);
	fclose(itemToRead);
	fclose(binToWrite);

}

