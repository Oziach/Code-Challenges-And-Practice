#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int divisibleSumPairs(int n, int k, vector<int> ar) {

    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if((ar[i] + ar[j])%k == 0){
                count++;
            }
        }
    }
    return count;
}

