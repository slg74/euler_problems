#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

int is_prime(uint64_t n); 
uint64_t prime_distance(uint64_t prev, uint64_t curr);

int main() {
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

    return 0;
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

