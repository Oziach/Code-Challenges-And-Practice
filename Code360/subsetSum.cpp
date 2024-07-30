bool util(int n, int k, vector<int> &a)
{

    if(k == 0){return true;}
    if(k < 0 || n <= 0){return false;}

    int currIndex = n-1;


    //return pick OR dont pick
    return util(n-1, k-a[currIndex], a) || util(n-1, k, a);
}

bool isSubsetPresent(int n, int k, vector<int> &a){
    return util(n, k, a);
}