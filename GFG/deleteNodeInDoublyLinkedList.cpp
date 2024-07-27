class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        
        Node* newHead = head;
        if(x == 1){newHead = head->next;}
        
        int currNode = 1;
        while(head && currNode < x){
            head = head->next;
            currNode++;
        }
        
        if(head->prev){head->prev->next = head->next;}
        if(head->next){head->next->prev = head->prev;}
        
        head->next = NULL;
        head->prev = NULL;
        delete head;
        
        return newHead;
    }
};