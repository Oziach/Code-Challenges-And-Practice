Node* revList(Node* head){
    
    Node* temp = NULL;
    Node* current = head_ref;
    
      while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != NULL)
        head_ref = temp->prev;
}

//Node* merge two lists ig
Node* MergeLists(Node* head1, Node* head2){
    Node* head = head1;
    while(head1!->next != NULL)
        head1 = head1->next;
    
    head1->next = head2;
    head2 ->prev = head1;
    
    return head;
}

Node* SortBiotonicDLL(Node* head){
    Node* current = head;
    
    while(current->next && current < current->next){
        current = current->next;
    }
    
    Node* head2 = current;
    head2->prev->next = NULL;
    
    head2 = revList(head2);
    MergeLists(head, head2);
    
    return head;
}