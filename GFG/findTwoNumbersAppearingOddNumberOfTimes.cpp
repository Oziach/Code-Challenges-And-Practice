class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {   
        long long xr = 0;
        
        for(int i = 0; i < N; i++){
            xr = xr ^ arr[i];
        }
        
        //find differing bit's index
        int diffIndex = 0;
        for(diffIndex = 0; diffIndex < 32; diffIndex++){
            if(1 & (xr >> diffIndex))
                break;
        }
        
        //group the numbers
        long long onesGroup = 0;
        long long zerosGroup = 0;
        
        for(int i = 0; i < N; i++){
            if(arr[i] >> diffIndex & 1)
                onesGroup ^= arr[i];
            else
                zerosGroup ^= arr[i];
        }
        
        if(onesGroup > zerosGroup){return {onesGroup, zerosGroup};}
        return {zerosGroup, onesGroup};
        
    }
};