/*
 * randstr.c
 * Created by WalkingMask on 2016/01/16.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

/* variables */
struct timeval myTime; // for rand more rand

// flags
int lng = 4;
int lower = 1;
int upper = 1;
int number = 1;

/* function prototypes */
void rputc(int start, int range);

int main(int ac, char **av) {
	char ch;
	while ((ch = getopt(ac, av, "l:aAnh")) != -1) {
		switch(ch) {
		case 'l':
			// lng must be int
			if ((lng = atoi(optarg)) == 0) {
				fprintf(stderr, "error: 1: length must be integer! \n");
				return 1;
			}
			break;
		case 'a':
			lower = 0;
			break;
		case 'A':
			upper = 0;
			break;
		case 'n':
			number = 0;
			break;
		case '?':
		case 'h':
		default:
			fprintf(stderr, "usage: randstr [-l length] [-a|A|n|h] \n");
			return 1;
		}
	}

	if (av[optind] != NULL) {
		fprintf(stderr, "illegal option %s\n", av[optind]);
		return 1;
	}

	// make rand more random using timeval.tv_usec
	srand((unsigned) myTime.tv_usec);

	// print random string
	int i;
	for (i=0; i<lng; i++) {
		gettimeofday(&myTime, NULL);
		switch (((random()%(RAND_MAX-1000000))+myTime.tv_usec)%3+1) {
		case 1: // -a
			if (lower == 1) {
				rputc(97, 25);
			} else {
				i--;
			}
			break;
		case 2: // -A
			if (upper == 1) {
				rputc(65, 25);
			} else { 
				i--;
			}
			break;
		case 3: // -n
			if (number == 1) {
				rputc(48, 10);
			} else {
				i--;
			}
			break;
		default:
			break;
		}
	}
	printf("\n");

	return 0;
}

// random put character with ascii
void rputc(int start, int range) {
	gettimeofday(&myTime, NULL);
	printf("%c", (char)(((random()%(RAND_MAX-1000000))+myTime.tv_usec)%range+start));
}