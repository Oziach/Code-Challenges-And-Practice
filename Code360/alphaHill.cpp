void alphaHill(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }

        for(int j = 0; j <= i; j++){
            cout <<  char('A' + j) << " ";
        }

        for(int j = i-1; j >= 0; j--){
            cout << char('A' + j) << " ";
        }

        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}