#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);
        sum += val;
    }

    // Mengambil nilai mutlak dari total penjumlahan
    if (sum < 0) {
        sum = -sum;
    }

    printf("%lld\n", sum);

    return 0;
}
