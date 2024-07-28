class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* curr = *head_ref;
        
        while(curr != NULL){
            if(curr->data == x){
                
                if(!curr->prev){*head_ref = curr->next;}
                
                if(curr->prev){curr->prev->next = curr->next;}
                if(curr->next){curr->next->prev = curr->prev;}
                Node* toDel = curr;
                curr = curr->next;
                
                toDel->prev = NULL; toDel->next = NULL;
                delete toDel;
            }
            else{
                curr = curr->next;
            }
        }
        
        return;
    }
};