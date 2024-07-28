/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int GetLen(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }

        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        int lenA = GetLen(headA);
        int lenB = GetLen(headB);

        ListNode* shorter = lenA < lenB ? headA : headB;
        ListNode* longer = lenA < lenB ? headB : headA;
        int smallerLen = min(lenA, lenB);
        int biggerLen = max(lenA, lenB);

        while(biggerLen != smallerLen){
            longer = longer->next;
            biggerLen--;
        }

        while(shorter != longer){
            shorter = shorter->next;
            longer = longer->next; 
        }

        return shorter;
    }
};