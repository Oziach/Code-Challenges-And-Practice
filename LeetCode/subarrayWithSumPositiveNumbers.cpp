int main(){
    
    int n, s;
    cin >> n >> s;
    
    map<int,int> sumToIndex;
    
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
       
        if(sumToIndex.count(sum - s)){
            cout << sumToIndex[sum-s]-1 << " " << i;
            return 0;
        }
        //else
        sumToIndex[sum] = i;
    }
    
    cout << -1;
    
    return 0;
}