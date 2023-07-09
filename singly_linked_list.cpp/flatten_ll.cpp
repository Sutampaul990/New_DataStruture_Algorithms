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

Node* merge(Node* down,Node* right)
{
	if(down==NULL)
	return right;

	if(right==NULL)
	return down;

	Node* ans = new Node(-1);
    Node* temp = ans;

	while(right!=NULL && down!=NULL)
	{
		if(down->data < right->data)
		{
			temp->child = down;
			temp =down;
			down = down->child;
		}
		else
		{
			temp->child = right;
			temp = right;
			right=right->child;
		}
	}
	
	if(down)
		temp->child = down;
	else
		temp->child = right;

	return ans->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next == NULL)
		return head;

	
	Node* down = head;
	// right = head->next;
	

	Node*right = flattenLinkedList(head->next);
	down->next = NULL;

	Node* ans = merge(down,right);
	return ans;
}
