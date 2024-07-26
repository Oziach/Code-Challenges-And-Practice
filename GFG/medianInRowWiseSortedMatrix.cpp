class Solution{   
public:
    
    int GetMin(vector<vector<int>>& mat){
        int mini = INT_MAX;
        for(vector<int> v : mat){
            mini = min(mini, v[0]);
        }
        
        return mini;
    }
    
     int GetMax(vector<vector<int>>& mat){
        int maxi = INT_MIN;
        for(vector<int> v : mat){
            maxi = max(maxi, v[v.size()-1]);
        }
        
        return maxi;
    }
    
    int GetLessThanEqualTo(vector<vector<int>>& mat, int num){
        int count = 0;
        for(vector<int> v : mat){
            count += upper_bound(v.begin(), v.end(), num) - v.begin();
        }
        return count;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int s = GetMin(matrix);
        int e = GetMax(matrix);
        int n = R * C;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            int lteCount = GetLessThanEqualTo(matrix, mid);
            if(lteCount > n/2){
                e = mid - 1;
            }
            else{
                s = mid+1;
            }

        }
        
        return s;
    }
};