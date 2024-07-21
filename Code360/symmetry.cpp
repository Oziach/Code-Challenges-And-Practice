void symmetry(int n) {
    int flip = 1;
    for(int i = 1; i >= 1; i += flip){
        for(int j = 0; j < i; j++){
            cout << '*' << " ";
        }

        for(int j = 0; j < n-i; j++){
            cout << " ";
        }

        for(int j = 0; j < i; j++){
            cout << '*' << "  ";
        }

        if(i == n){flip = -1;}
        cout << endl;
    }

}