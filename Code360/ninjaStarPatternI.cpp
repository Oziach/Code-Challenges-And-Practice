void getStarPattern(int n) {

    if(n == 1){cout << '*'; return;}

    for(int i = 0; i < n; i++){
        cout << '*';
    }   
    cout << endl;

    for(int i = 0; i < n-2; i++){
        cout << '*';

        for(int j = 0; j < n-2; j++){
            cout << " ";
        }

        cout << '*';
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        cout << '*';
    }   
}
