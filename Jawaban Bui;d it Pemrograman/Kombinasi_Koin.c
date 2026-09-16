#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>



#define MOD 1000000007L

// Fungsi pembanding untuk qsort
int compare(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    long long *arr = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // Urutkan nilai koin
    qsort(arr, n, sizeof(long long), compare);

    // Total kombinasi memilih 2 koin dari N koin
    long long total_pairs = (n % MOD) * ((n - 1) % MOD) % MOD;
    // Bagi dengan 2 (menggunakan invers modular untuk 2 modulo 10^9+7 adalah 500000004)
    total_pairs = (total_pairs * 500000004LL) % MOD;

    long long invalid_pairs = 0;
    long long freq = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            freq++;
        } else {
            if (freq > 1) {
                long long same_pairs = (freq % MOD) * ((freq - 1) % MOD) % MOD;
                same_pairs = (same_pairs * 500000004LL) % MOD;
                invalid_pairs = (invalid_pairs + same_pairs) % MOD;
            }
            freq = 1;
        }
    }
    // Untuk elemen kelompok terakhir
    if (freq > 1) {
        long long same_pairs = (freq % MOD) * ((freq - 1) % MOD) % MOD;
        same_pairs = (same_pairs * 500000004LL) % MOD;
        invalid_pairs = (invalid_pairs + same_pairs) % MOD;
    }

    // Pasangan valid = Total Pasangan - Pasangan Sama
    long long ans = (total_pairs - invalid_pairs + MOD) % MOD;

    printf("%lld\n", ans);

    free(arr);
    return 0;
}