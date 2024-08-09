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

class Comp{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }

};

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, Comp> minHeap;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) minHeap.push(lists[i]);
        }

        //iterate through the lists
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();

            dummyTail->next = top;
            dummyTail = dummyTail->next;

            ListNode* next = top->next;

            if(next) minHeap.push(next);
        }

        return dummyHead->next;
    }
};