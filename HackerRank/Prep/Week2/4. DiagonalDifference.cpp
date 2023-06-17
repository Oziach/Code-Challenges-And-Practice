/*Question:

Given a square matrix, calculate the absolute difference between the sums of its diagonals. 

*/

//Solution

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int maxIndex = arr.size() - 1;
    int sum1 = 0; 
    int sum2 = 0;
    
    for(int i = 0; i <= maxIndex; i++){
        sum1 += arr[i][i];
        sum2 += arr[i][maxIndex - i];
    }
    
    return(abs(sum1 - sum2));
}