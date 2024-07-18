class Solution
{
    private:
    Node* rev(Node* head){
        Node* current = head;
        Node* prev = NULL;
        Node* next;
        
        while(current != NULL){
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* revHead1 = rev(first);
        Node* revHead2 = rev(second);
        
        Node* it1 = revHead1;
        Node* it2 = revHead2;
        
        Node* ansHead = new Node(-1);
        Node* ansTail = ansHead;
        
        int carry = 0;
        
        
        while(it1 != NULL || it2 != NULL){
            
            int val1 = it1 ? it1->data : 0;
            int val2 = it2 ? it2->data : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum/10;
            sum = sum % 10;
            
            ansTail->next = new Node(sum);
            ansTail = ansTail->next;
            
            if(it1) {it1 = it1->next;}
            if(it2) {it2 = it2->next;}
        }
        
        if(carry){
            ansTail->next = new Node(carry); 
            ansTail = ansTail -> next;
        }
        
        rev(revHead1);
        rev(revHead2);
        
        
        
        return rev(ansHead->next);
    }
};