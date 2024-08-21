#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum1 = 0;
    int sum2 = 0;
    set<int> s1;
    set<int> s2;

    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;

        if(s1.find(ele)){
            s2.insert(ele);
            sum2 += ele;
        }
        else if(s2.find(ele)){
            s1.insert(ele);
            sum1 += ele;
        }
        else{
            if(ele > 0){
                s1.insert(ele);
                sum1 += ele;
            }
            else{
                s2.insert(ele);
                sum2 += ele;
            }
        }

        cout << sum1 - sum2;
    }
}