class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {   
        if(n <= 1){return n;}
        
        int p = log2(n);
        
        return (p * pow(2, p-1)) + (n - pow(2,p)+1) + countSetBits(n - pow(2,p)); 
    }
};
