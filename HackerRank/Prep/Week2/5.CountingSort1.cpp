/*Question:

Given a list of integers, count and return the number of times each value appears as an array of integers.

*/

//Solution

/*
 * Complete the 'countingSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> countingSort(vector<int> arr) {
    
    int size = arr.size();
    vector<int> countingArray(100,0);  
    
    for(int i = 0; i < arr.size(); i++){
        int num = arr[i];
        countingArray[num]++;
    }
    
    return countingArray;
}

