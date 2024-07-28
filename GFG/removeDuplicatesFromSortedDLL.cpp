class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* curr = head->next;
        
        while(curr){
            if(curr->data == curr->prev->data){
                if(curr->prev) curr->prev->next = curr->next;
                if(curr->next) curr->next->prev = curr->prev;
                Node* toDel = curr;
                curr = curr->next;
                
                toDel->next = NULL;
                toDel->prev = NULL;
                delete toDel;
            }
            else{
                curr = curr->next;
            }
        }
        
        return head;
    }
};