#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int sum = 0;
    for(int i = 0; i < 3; i++){
        int num;
        cin >> num;
        sum += num;
    }   
    cout << sum;
    return 0;
}
