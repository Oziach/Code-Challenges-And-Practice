#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    
    stringstream ss(str);
    char comma;
    int num;
    vector<int> nums;
    
    while(ss >> num){
        nums.push_back(num);
        ss >> comma;
    }
    return nums;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}