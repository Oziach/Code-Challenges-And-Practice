lass Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            
            while(i < n-1 && arr1[i] == arr1[i+1])
                i++;
            while(j < m-1 && arr2[j] == arr2[j+1])
                j++;
            
            if(arr1[i] < arr2[j]){
                ans.push_back(arr1[i]);
                i++;
                
            }
            else if(arr1[i] > arr2[j]){ 
                ans.push_back(arr2[j]);
                j++;
            }
            else{ //if equal
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            
        }
        
        while(i < n){if(arr1[i] == arr1[i+1]) i++; else ans.push_back(arr1[i++]);}
        while(j < m){if(arr2[j] == arr2[j+1]) j++; else ans.push_back(arr2[j++]);}
        
        return ans;
    }
};