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
    int GetLength(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }

        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL){return head;}
        int len = GetLength(head);
        k = k % len;
        if(k == 0){return head;}

        int counter = len - k - 1;

        ListNode* curr = head;
        while(counter--){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;
        curr = newHead;

        while(curr->next){
            curr = curr->next; //get tail
        }
        curr->next = head;

        return newHead;
    }
};