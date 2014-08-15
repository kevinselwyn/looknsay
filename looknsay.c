#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(__APPLE__)
#include <malloc.h>
#endif

void next_num(char **next, char *num) {
	int length = 0, count = 0, total = 0, offset = 0;
	int i = 0, j = 0, k = 0, l = 0;
	char *tmp = NULL;

	length = (int)strlen(num);

	tmp = malloc(sizeof(char) * (length) + 1);
	strcpy(tmp, num);

	for (i = 0, j = length; i < j; i += count) {
		count = 1;

		for (k = i + 1, l = length; k < l; k++) {
			if (tmp[k] == tmp[i]) {
				count++;
			} else {
				k = l;
			}
		}

		total++;
	}

	*next = malloc(sizeof(char) * (total * 2) + 1);

	for (i = 0, j = length; i < j; i += count) {
		count = 1;

		for (k = i + 1, l = length; k < l; k++) {
			if (tmp[k] == tmp[i]) {
				count++;
			} else {
				k = l;
			}
		}

		offset += sprintf(*next + offset, "%d%c", count, tmp[i]);
	}

	free(tmp);
}

int main(int argc, char *argv[]) {
	int rc = 0, iterations = 10, i = 0, l = 0;
	char *num = NULL;

	if (argc < 2) {
		printf("Usage: %s <start> <iterations>\n", argv[0]);

		rc = 1;
		goto cleanup;
	}

	num = malloc(sizeof(char) * (int)strlen(argv[1]) + 1);
	num = argv[1];

	if (argc > 2) {
		iterations = atoi(argv[2]);
	}

	printf("%s\n", num);

	for (i = 0, l = iterations; i < l; i++) {
		next_num(&num, num);
		printf("%s\n", num);
	}

cleanup:
	if (num) {
		free(num);
	}

	return rc;
}
