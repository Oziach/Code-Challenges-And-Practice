#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> nextSmaller(n);

    for(int i = n-1; i >= 0; i--){
        
        while(st.top() >= arr[i]){
            st.pop();
        }

        nextSmaller[i] = st.top();
        st.push(arr[i]);
    }

    return nextSmaller;
}