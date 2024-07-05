/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void Place(stack<int>& s, int num){
    
    if(s.empty() || s.top() <= num){
        s.push(num);
        return;
    }
    
    int ele = s.top();
    s.pop();
    
    Place(s, num);
    
    s.push(ele);
}

void SortedStack :: sort()
{
    if(s.empty()){
        return;
    }
    
   int ele = s.top();
   s.pop();
   
   sort();
   Place(s, ele);
}