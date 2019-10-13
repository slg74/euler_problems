#include <stdio.h>

#define UPPER 28123

int abundant[UPPER] = {-1};

int is_sum(int n);
int is_abundant(int n); 

int main() {
    int sum;
    int i;
    for (i=0; i < UPPER; i++) {
        abundant[i] = -1; 
    }

    sum = 0;
    for (i=1; i < UPPER; i++) {
        if (!is_sum(i)) {
            sum += i;
        }
    }
    printf("%d\n", sum); 
    return 0;
}

int is_abundant(int n) {
    int i;
    int sum = 1;
    for (i=2; i*i < n; i++) {
        if (n%i == 0) {
            sum += (i + n/i); 
        }
    }
    if (i*i == n) {
        sum += i;
    }
    abundant[n] = (sum > n) ? 1 : 0; 
    return abundant[n]; 
}

int is_sum(int n) {
    int i;
    for (i=12; i <= n/2; i++) {
        if (is_abundant(i) && is_abundant(n-i)) {
            return 1;
        }
    }
    return 0;
}

