#include <bits/stdc++.h> 
#define MOD 1000000007

int numberOfWays(int n, int k) {
    int total = k;
    int differentColoured = k;

    for(int i = 2; i <= n; i++){
        int sameColoured = differentColoured%MOD;
        differentColoured = (1LL * total * (k-1))%MOD;
        total = (sameColoured + differentColoured)%MOD;
    }

    return total;
}
