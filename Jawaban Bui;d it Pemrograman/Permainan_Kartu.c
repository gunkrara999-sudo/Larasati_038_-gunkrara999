#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort(long long *a, long long *b, long long *c) {
    long long temp;
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
}

int main() {
    long long a, b, c;
    if (scanf("%lld %lld %lld", &a, &b, &c) != 3) return 0;

    long long rounds = 0;

    while (1) {
        // Urutkan nilai sehingga a <= b <= c
        sort(&a, &b, &c);

        // Jika ada dua pemain dengan jumlah kartu yang sama, permainan berakhir
        if (a == b || b == c) {
            break;
        }

        // Pemain kartu terbanyak (c) memberikan 1 kartu ke yang tersedikit (a)
        c--;
        a++;
        rounds++;
    }

    printf("%lld\n", rounds);

    return 0;
}