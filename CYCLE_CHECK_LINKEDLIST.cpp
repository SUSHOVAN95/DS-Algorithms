#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
	int val;
	struct Node* next;
}Node;

Node* insert(Node* head,int val)
{
	Node *newnode = new Node;
	Node *cur = head;
	
	newnode->val = val;
	
	if(head==NULL)
	{		
		newnode->next = head;
		head = newnode; 
	}
	else
	{
		while(cur->next!=NULL)
		{
			cur = cur->next;
		}
		
		newnode->next = cur->next;
		cur->next = newnode;
	}
	
	return head;
}

void display(Node* head)
{
	Node* cur = head;
	while(cur!=NULL)
	{
		cout<<cur->val<<" ";
		cur = cur->next;
	}
}

bool cyclecheck(Node* head)
{
	set<Node *> S;
	Node* cur = head;
	
	while(cur!=NULL)
	{
		if(S.find(cur)!=S.end())
		{
			return true;
		}
		
		S.insert(cur);
		cur = cur->next;
	}
	
	return false;

}

/*
Floyd’s Cycle-Finding Algorithm:
This is the fastest method. 
Traverse linked list using two pointers.  
Move one pointer by one and other pointer by two.
If these pointers meet at same node then there is a loop.If pointers do not meet then linked list doesn’t have loop
*/
int detectloop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
   
    while (slow_p && fast_p && fast_p->next ) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
        if (slow_p == fast_p) 
        { 
           return 1; 
        } 
    } 
    return 0; 
} 

int main()
{
	Node *head = NULL;
	
	head = insert(head,5);
	insert(head,15);
	insert(head,10);
	insert(head,25);
	
	Node* cur = head;
	
	while(cur->next!= NULL)
	{
		cur = cur->next;
	}
	
	//cur->next = head;
	
	bool tf = cyclecheck(head);
	
	if(tf==true)
	{
		cout<<"Cycle found"<<endl;
	}
	else
	{
		cout<<"Cycle not found"<<endl;
	}
	
	return 0;
}

