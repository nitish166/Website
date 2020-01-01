#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mod 1000000007
typedef long long int LL;


class Node{
public:
	int data;
	Node* prev;
	Node* next;
};

// At the front of The DDL

void FrontInsert(Node** head, int data)
{
	Node* new_data = new Node();
	new_data->data = data;
	new_data->next = (*head);
	new_data->prev = NULL;

	// change prev of head to new node
	if((*head) !=NULL)
	{
		(*head)->prev = new_data;
	}
	// move the head to pint the new node
	(*head) = new_data;

}



// After a given node

void AfterNode(Node* prev_node , int data)
{
	Node* new_head = new Node();
	new_head->data = data;

	new_head->next = prev_node->next;
	
	prev_node->next = new_head;

	new_head->prev = prev_node;

	if(new_head->next !=NULL)
	{
		new_head->next->prev = new_head;
	}
}



// At the end of linked list
void EndNode(Node** prev_node, int data)
{
	//1. Allocate node
	Node *new_node = new Node();

	//2. put in the data
	new_node->data = data;

    // used in step 5.
	Node* last = *prev_node;

	//3. this new node is going to last node. so, put in NULL

	new_node->next = NULL;

	// 4. if new linked list is empty, then make new node as head

	if(*prev_node == NULL)
	{
		new_node->prev = NULL;
		*prev_node = new_node;
		return;
	}

	// 5. else traverse till the last node

	while(last->next !=NULL)
	{
		last=last->next;
	}

	//6. change the next of last node

	last->next = new_node;

	//7. make last node as previous of new node

	new_node->prev = last;

	return;

}



// for printing the linked list
void Print(Node* node)
{
	Node* last;
	// in case of single limked list
	cout<<"Traversing in the forward direction :"<<endl;
	while(node !=NULL)
	{

		cout<<node->data<<" ";
		last = node;
		node = node->next;
	}
	cout<<endl;
	cout<<"Traversing in the backward direction :"<<endl;

	while(last !=NULL)
	{
		cout<<last->data<<" ";
		last=last->prev;
	}

}

 
int main()
{
   Node* node = NULL;
   FrontInsert(&node, 6);
   FrontInsert(&node, 12);
   FrontInsert(&node, 14);
   FrontInsert(&node, 1);
   AfterNode(node->next, 4);

   Print(node);
   return 0;
}