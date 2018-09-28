#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "wrong number of command line arguments\n");
		return(-1);
	}

	FILE* toOpen;
	toOpen = fopen(argv[1], "r"); 

	FILE* toWrite;
	toWrite = fopen(argv[2], "wb");

	int c;

	const size_t line_size = 300;
	char* line = malloc(line_size);
	size_t count = 0;
	char* lastSpace = 0;
	char** splitStrings = 0;
	while (fgets(line, line_size, toOpen) != NULL) {
		const char tab = '\t';
		char _tab[2];
		_tab[0] = tab;
		_tab[1] = 0;
		char** splitStrings = 0;
		size_t count = 0;
		char* temp = line;
		char* lastTab = 0;
		while (*temp) {
			if (tab == *temp) {
				count++;
				lastTab = temp;
			}
			temp++;
		}
		count += lastTab < (line + strlen(line) -1);
		count++;
		splitStrings = malloc(sizeof(char*) * count);

		if (splitStrings) {
			size_t idx = 0;
			char* token = strtok(line, _tab);

			while (token) {
				*(splitStrings + idx++) = strdup(token);
				token = strtok(0, _tab);
			}
			*(splitStrings + idx) = 0;
		}

		/*printf("Here is a thing: \n");
		printf(splitStrings[0]);
		printf("\n");
		printf(splitStrings[1]);
		printf("\n");*/

		unsigned short uid;
		uid = (unsigned short) atoi(splitStrings[0]);
		//printf("%hu", uid);
		//printf("\n");
		unsigned short iid;
		iid = (unsigned short) atoi(splitStrings[1]);
		unsigned char rating;
		rating = (unsigned char) atoi(splitStrings[2]);
		unsigned long timestamp;
		timestamp = (unsigned long) atoi(splitStrings[3]);

		fwrite(&uid, sizeof(uid), 1, toWrite);
		fwrite(&iid, sizeof(iid), 1, toWrite);
		fwrite(&rating, sizeof(rating), 1, toWrite);
		fwrite(&timestamp, sizeof(timestamp), 1, toWrite);
	}
	free(splitStrings);
	free(line);
	fclose(toOpen);
	fclose(toWrite);

	return(0);
}
