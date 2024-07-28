/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

void AddToTail(Node*& head, Node*& tail, Node* node){
	if(head == NULL){
		head = tail = node;
	}
	else{
		tail->child = node;
		tail = tail->child;
	}
}

Node* MergeSortedLLs(Node* head1, Node* head2){
	Node* curr1 = head1;
	Node* curr2 = head2;

	Node* sortedHead = NULL;
	Node* sortedTail = NULL;

	while(curr1 && curr2){
		if(curr1->data < curr2->data){
			AddToTail(sortedHead, sortedTail, curr1);
			curr1 = curr1->child;
		}
		else{
			AddToTail(sortedHead, sortedTail, curr2);
			curr2 = curr2->child;
		}
	}
	if(curr1){
		AddToTail(sortedHead, sortedTail, curr1);
	}
	if(curr2){
		AddToTail(sortedHead, sortedTail, curr2);
	}

	//sortedTail->child = NULL; DON'T DO THIS LOL
	return sortedHead;
}

Node* flattenLinkedList(Node* head) 
{	
	if(head == NULL || head->next == NULL){return head;}

	Node* sorted = flattenLinkedList(head->next);
	head->next = NULL;
	return MergeSortedLLs(head, sorted);
}
