#include <bits/stdc++.h> 

void delMiddle(stack<int>& st, int N){
   
   if(N == 0){st.pop(); return;}

   int ele = st.top();
   st.pop();

   delMiddle(st, N-1);
   st.push(ele);
}

void deleteMiddle(stack<int>& inputStack, int N){
   delMiddle(inputStack, N/2);
}