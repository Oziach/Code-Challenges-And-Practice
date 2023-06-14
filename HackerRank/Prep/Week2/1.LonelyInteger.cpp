/*Question:

Given an array of integers, where all elements but one occur twice, find the unique element. 

*/

//Solution

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(vector<int> a) {
    int arr[101] = {0};
    
    for(int i = 0; i < a.size(); i++){
        arr[a[i]]++;
    }
    
    for(int i = 0; i < 101; i++){
        if(arr[i] == 1){
            return i;
        }
    }
    return -1;
}
