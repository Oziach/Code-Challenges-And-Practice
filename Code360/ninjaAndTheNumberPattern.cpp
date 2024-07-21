void getNumberPattern(int n) {

    int flip1 = 1;
    for(int i = 0; i >= 0; i+= flip1){
        int num = n;

        for(num; num > n-i; num--){
            cout << num;
        }

        for(int j = 0; j < n*2 - 2*i - 1; j++){
            cout << num;
        }
        
        for(num+=1; num <= n; num++){
            cout << num;
        }
        cout << endl;
        if(i == n-1){flip1 = -1;}
    }
}