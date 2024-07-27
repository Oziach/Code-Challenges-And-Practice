/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:

    void AddNode(ListNode*& head, ListNode*& tail, ListNode*& node){
        if(head == NULL){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = tail->next;
        }
    }

public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = NULL;
        ListNode* oddTail = NULL;
        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;

        int index = 1;
        while(head){
            if(index & 1){
                AddNode(oddHead, oddTail, head);
            }
            else{
                AddNode(evenHead, evenTail, head);
            }
            head = head->next;
            index++;
        }

        if(evenTail){evenTail->next = NULL;}
        if(oddTail) {oddTail->next = evenHead;}

        if(oddTail == NULL){return evenHead;}
        return oddHead;
    }
};
