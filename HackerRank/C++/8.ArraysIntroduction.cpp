#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[n-1-i];
    }   
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}
