int findDuplicate(vector<int> &arr) 
{
    
    for(int i = 0; i < arr.size(); i++){
        int element = abs(arr[i]);
        int hash = element - 1;

        if(arr[hash] < 0){
            return abs(element);
        }
        else{
            arr[hash] *= -1;
        }

    }

    return -1;
    
}