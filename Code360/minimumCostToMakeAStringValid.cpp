#include <bits/stdc++.h> 
int findMinimumCost(string str) {
    string rem;

    //odd length string
    if(str.length() & 1){return -1;}

    for (char ch : str) {
        if (ch == '}'){
            if(rem.length() > 0 && rem[rem.length()-1] == '{'){
                rem.pop_back();
            }
            else{
                rem += ch;
            }
        }
        else{
            rem += ch;
        }
    }

    //perfectly valid string
    if(rem.length() == 0){return 0;}

    int openCount = 0;
    for(char ch : rem){
        if (ch == '{')
            openCount++;
    }
    
    return openCount & 1 ? rem.length()/2 + 1 : rem.length()/2;