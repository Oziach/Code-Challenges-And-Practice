
int findUnique(int *arr, int size) {
    
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum ^ arr[i];
    }
    return sum;
}