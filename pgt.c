#include <limits.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define NUM_THREADS 4  /* MacOSX - sysctl -n hw.ncpu == 4 */

/* pg.c - find prime gaps from 0 - ULLONG_MAX */

int is_prime(uint64_t n); 
uint64_t prime_distance(uint64_t prev, uint64_t curr);
void *mt_prime_gap(void *thread_id); 

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int rc;
    for (i=0; i<NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, mt_prime_gap, (void *)i); 
    }
    pthread_exit(NULL); 
}

void *mt_prime_gap(void *thread_id) {
    long tid;
    tid = (long)thread_id;

    time_t current_time;
    char* c_time_string;

    uint64_t curr=0;
    uint64_t prev=0;
    uint64_t prime_gap=0;
    uint64_t largest_gap=0;

    FILE *output = fopen("sparse_primes.dat", "w"); 

    for (uint64_t i=0; i<=ULLONG_MAX; i++) {

        if (is_prime(i)) {

            curr = i;
            prime_gap = prime_distance(prev, curr);

            if (prime_gap > largest_gap) {

		current_time = time(NULL); 
		c_time_string = ctime(&current_time);

          	largest_gap = prime_gap;
                printf("%lld - %lld: %lld date: %s", prev, curr, largest_gap, c_time_string);
                fprintf(output, "%lld - %lld: %lld date: %s", prev, curr, largest_gap, c_time_string);

            }
            prev = curr;
        }
    }
    fclose(output); 

    pthread_exit(NULL); 
}


int is_prime(uint64_t n) {
    for (uint64_t i=2; i<n; i++) {
        if (n%i == 0 && i != n) { 
            return 0;
        } 
    }
    return 1;
}


uint64_t prime_distance(uint64_t prev, uint64_t curr) {
    uint64_t dist;
    dist = curr - prev;
    return dist;
}

