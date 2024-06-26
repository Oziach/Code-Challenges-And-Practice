#include<iostream>

using namespace std;

char flip(char a){
    if(a=='6') return '9';
    if(a=='9') return '6';
    return a;
}

int main()
{
    string input;
    cin >> input;
    
    string flipped;
    
    for(int i = input.length()-1 ; i >= 0; i--){
        flipped+=flip(input[i]);
    }
    
    input == flipped ? cout << "Yes" : cout << "No";
    return 0;
}