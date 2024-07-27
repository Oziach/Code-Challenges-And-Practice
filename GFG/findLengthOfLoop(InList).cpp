Node* GetIntersection(Node* head){
    Node* fast = head;
    Node* slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow -> next;
        
        if(slow == fast){
            return slow;
        }
    }
    
    return NULL;
}


int countNodesinLoop(struct Node *head)
{
    Node* loopNode = GetIntersection(head);
    
    if(!loopNode){return 0;}
    
    int count = 0;
    Node* curr = loopNode;
    
    while(curr->next != loopNode){
        count++;
        curr = curr->next;
    }
    
    return count+1;
}