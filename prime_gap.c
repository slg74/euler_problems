#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int is_prime(unsigned long long n); 
unsigned long long prime_distance(unsigned long long prev, unsigned long long curr);

int main() {
    time_t current_time;
    char* c_time_string;

    unsigned long long curr=0;
    unsigned long long prev=0;
    unsigned long long prime_gap=0;
    unsigned long long largest_gap=0;

    FILE *output = fopen("sparse_primes.dat", "w"); 

    for (unsigned long long i=0; i<=ULLONG_MAX; i++) {

        if (is_prime(i)) {

            curr = i;
            prime_gap = prime_distance(prev, curr);

            if (prime_gap > largest_gap) {

		current_time = time(NULL); 
		c_time_string = ctime(&current_time);

          	largest_gap = prime_gap;
                printf("%llu - %llu: %llu date: %s", prev, curr, largest_gap, c_time_string);
                fprintf(output, "%llu - %llu: %llu date: %s", prev, curr, largest_gap, c_time_string);

            }
            prev = curr;
        }
    }
    
    fclose(output); 

    return 0;
}

int is_prime(unsigned long long n) {
    for (unsigned long long i=2; i<n; i++) {
        if (n%i == 0 && i != n) { 
            return 0;
        } 
    }
    return 1;
}

unsigned long long prime_distance(unsigned long long prev, unsigned long long curr) {
    unsigned long long dist;
    dist = curr - prev;
    return dist;
}

