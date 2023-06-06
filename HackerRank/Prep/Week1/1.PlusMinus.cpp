/*Question:
Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal 
value of each fraction on a new line with places after the decimal.
*/

//Solution

void plusMinus(vector<int> arr) {
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    int totalCount = arr.size();
    
    for(int i = 0; i < totalCount; i++)
    {
        if(arr[i] == 0) 
        {
            zeroCount++;
        }
        else if (arr[i] < 0)
        {
            negativeCount++;
        }
        else
        {
            positiveCount++;
        }
    }
    //print ratios
    cout << setprecision(6) << (float)positiveCount/totalCount << endl;
    cout << setprecision(6) << (float)negativeCount/totalCount << endl;
    cout << setprecision(6) << (float)zeroCount/totalCount << endl;
    
   
}