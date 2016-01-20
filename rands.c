/*
 * rands.c
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
int lng = 8;
int a_flag = 1;
int A_flag = 1;
int n_flag = 1;
int s_flag = 1;
int S_flag = 0;

/* function prototypes */
void rsymbol();
void rputc(int start, int range);

int main(int ac, char **av)
{

/* manage arguments */
	// set flag with option
	char ch;
	while ((ch = getopt(ac, av, "l:aAnsSh")) != -1) {
		switch(ch) {
		case 'l':
		    // lng must be int
			if((lng = atoi(optarg)) == 0){ fprintf(stderr, "error: 1: length must be integer! \n"); return 1; }
			break;
		case 'a':
			a_flag = 0;
			break;
		case 'A':
			A_flag = 0;
			break;
		case 'n':
			n_flag = 0;
			break;
		case 's':
			s_flag = 0;
			break;
		case 'S':
			S_flag = 1;
			break;
		case '?':
		case 'h':
		default:
			fprintf(stderr, "usage: rands [-l length] [-a|A|n||s|S|h] \n");
			return 1;
		}
	}
	//
	if(av[optind] != NULL) { fprintf(stderr, "illegal option %s\n", av[optind]); return 1; }

    // make rand more random using timeval.tv_usec
    srand((unsigned) myTime.tv_usec);

/* main */

    // print random string
    int i;
    for(i=0; i<lng; i++){
        gettimeofday(&myTime, NULL);
    	switch(((random()%(RAND_MAX-1000000))+myTime.tv_usec)%5+1){
    	case 1: // -a
    		if(a_flag == 1){ rputc(97, 25); }
    		else{ i--; }
    		break;
    	case 2: // -A
    		if(A_flag == 1){ rputc(65, 25); }
    		else{ i--; }
    		break;
    	case 3: // -n
    		if(n_flag == 1){ rputc(48, 10); }
    		else{ i--; }
    		break;
    	case 4: // -s
    		if(s_flag == 1){ rsymbol(); }
    		else{ i--; }
    		break;
    	case 5: // -S
    		if(S_flag == 1){ printf(" "); }
    		else{ i--; }
    		break;
    	default:
    		break;
    	}
    }
    printf("\n");

    return 0;
}

// random put character with ascii
void rputc(int start, int range)
{
    gettimeofday(&myTime, NULL);
	printf("%c", (char)(((random()%(RAND_MAX-1000000))+myTime.tv_usec)%range+start));
}

// random symbol range
void rsymbol()
{
    gettimeofday(&myTime, NULL);
	switch(((random()%(RAND_MAX-1000000))+myTime.tv_usec)%4+1){
    	case 1: // 33~47
    		rputc(33, 15);
    		break;
    	case 2: // 58~64
    		rputc(58, 7);
    		break;
    	case 3: // 91~96
    		rputc(91, 6);
    		break;
    	case 4: // 123~126
    		rputc(123, 4);
    		break;
    	default:
    		break;
    	}
}
