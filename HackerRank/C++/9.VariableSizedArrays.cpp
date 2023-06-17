#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr[n];
    
    //input array matrix thing
    for(int i = 0; i < n; i++){
        int k; 
        cin >> k;
        for(int j = 0; j < k; j++){
            int aij;
            cin >> aij;
            arr[i].push_back(aij);
        }
    }
    
    //input queries and print respectively
    for(int z = 0; z < q; z++){
       int i, j;
       cin >> i >> j;
       cout << arr[i][j] << endl; 
    }
    return 0;
}