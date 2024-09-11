#include <stdio.h>
#include <stdlib.h>

long get_collatz_chain(long n);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        exit -1;
    }

    long i = atol(argv[1]); 
    long j = atol(argv[2]); 

    long start = i;

    long final = 0;
    long tmp = 0; 
    long len = 0; 

    for (i = start; i < j; i++) {
        len = get_collatz_chain(i); 
        if (len > tmp) {
            tmp = len;
            final = i;
        }
    }
    printf("%ld %ld %ld\n", start, j, len); 

    return 0;
}


long get_collatz_chain(long n) {

    long count_even = 1; 
    long count_odd = 1;
   
    long count = 1; 

    while (n != 1) {
        if (n%2 == 0) {
            n = n/2;
            count_even++;
        } 
        else {
            n = (n*3) + 1;    
            count_odd++;
        }
        count = count_even + count_odd; 
    } 

    return count;
}

