#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    
    int* arr = new int[n];
    
    int ascFirstIndex = 0;
    int descLastIndex = 0;
    
    int ascCurrIndex = 0;
    
    bool asc = true;
    
    cin >> arr[0];
    
    for(int i = 1; i < n ; i++){
        cin >> arr[i];
        
        if(asc && arr[i]  > arr[i-1]){
            
            if(descLastIndex - ascFirstIndex < i - ascCurrIndex){
                descLastIndex = i;
                ascFirstIndex = ascCurrIndex;
            }
        }
        else if(asc && arr[i] < arr[i-1]){
            asc = false;
            if(descLastIndex - ascFirstIndex < i - ascCurrIndex){
                ascFirstIndex =  ascCurrIndex;
                descLastIndex = i;
            }
        }
        else if(!asc && arr[i-1] > arr[i]){
            if(descLastIndex - ascFirstIndex < i - ascCurrIndex){
                descLastIndex = i;
                ascFirstIndex = ascCurrIndex;
            }
        }
        else if(!asc && arr[i-1] < arr[i]){
            asc = true;
            if(descLastIndex - ascFirstIndex < i-1 - ascCurrIndex){
                descLastIndex = i;
                ascFirstIndex = ascCurrIndex;
            }
            ascCurrIndex = i-1;
        }

    }
    
    cout << descLastIndex - ascFirstIndex  + 1 << endl;
    for(int i = ascFirstIndex; i <= descLastIndex; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}