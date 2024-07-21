void nStarDiamond(int n) {
    
    for(int i = 1; i <= n; i++){
        pair<int,int> range = {n-i+1, n+i-1};
        for(int j = 1; j <= 2*n-1; j++){
            if(j >= range.first && j <= range.second){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }

    for(int i = n; i >= 1; i--){
        pair<int,int> range = {n-i+1, n+i-1};
        for(int j = 1; j <= 2*n-1; j++){
            if(j >= range.first && j <= range.second){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}