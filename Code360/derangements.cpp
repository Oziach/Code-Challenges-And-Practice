#include<bits/stdc++.h>
#define MOD 1000000007

long long GetDerangementsRec(int n){
    if(n == 1){return 0;}
    if(n == 2){return 1;}

    return (n-1) * (GetDerangementsRec(n-1) + GetDerangementsRec(n-2));
}

long long GetDerangementsMem(int n, vector<int>& numberOfDerangements){
    if(n == 1){return 0;}
    if(n == 2){return 1;}
    
    if(numberOfDerangements[n] != -1){return numberOfDerangements[n];}

    return numberOfDerangements[n] = ((n-1) * (GetDerangementsMem(n-1, numberOfDerangements) + GetDerangementsMem(n-2, numberOfDerangements)))%MOD;
}

long long GetDerangementsTab(int n){
    vector<long long int> derangements(n+1, 0);

    derangements[1] = 0;
    derangements[2] = 1;

    for(int i = 3; i <= n; i++){
        long long first = derangements[i-1]%MOD;
        long long second = derangements[i-2]%MOD;
        long long sum = (first+second)%MOD;
        long long ans = ((i-1) * sum)%MOD;
        derangements[i] = ans;
    }

    return derangements[n];
}

long long GetDerangementsSO(int n){
    long long first = 0;
    long long second = 1;

    for(int i = 3; i <= n; i++){
        long long current = (first+second)%MOD;
        current = (current * (i-1))%MOD;

        first = second;
        second = current;
    }

    return second;
}

long long int countDerangements(int n) {
    //vector<int> numberOfDerangements(n+1, -1);
    return GetDerangementsSO(n);
}