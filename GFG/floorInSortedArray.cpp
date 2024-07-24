class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    long long BinarySearch(vector<long long>& v, long long& x, long long s, long long e){
        
        if(s > e) {return -1;}
        
        long long mid = s + (e-s)/2;
        
        if(v[mid] <= x){
            return max(mid, BinarySearch(v, x, mid+1, e));
        }
        else{
            return BinarySearch(v, x, s, mid-1);
        }
        
    }
    
    int findFloor(vector<long long> &v, long long n, long long x) {
        return BinarySearch(v, x, 0, n-1);
    }
};