class Solution {
  private:
  

  public:
    int extractMax() {
        
        int popped = H[0];
        swap(H[0], H[s--]);
        
        if(s) shiftDown(0);
        
        return popped;
    }
};
