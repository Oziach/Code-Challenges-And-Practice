/*Question:
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the 
five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers. 
*/

//Solution
void miniMaxSum(vector<int> arr) {
    
    int min = arr[0];
    int max = arr[0];
    unsigned int totalSum = 0;
    
    for(int i = 0; i < arr.size(); i++){
        
        totalSum += arr[i];
        
        if(min > arr[i]){
            min = arr[i];
        }
        
        if(max < arr[i]){
            max = arr[i];
        }
        
    }
    
    cout << totalSum - max << " " << totalSum - min; 
    
}
