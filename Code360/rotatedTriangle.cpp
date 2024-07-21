void nStarTriangle(int n) {
    int flip = 1;
    for(int i = 1; i >= 1; i += flip){
        for(int j = 0; j < i; j++){
            cout << '*';
        }
        cout << endl;

        if(i == n){flip = -1;}
    }
}