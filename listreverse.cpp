#include<bits/stdc++.h>

using namespace std;

struct Node
{
  char val;
  struct Node* next;
};

struct Node* insert(struct Node* head,char data)
{
    struct Node* cur = head;
    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));

    
    NEW->val = data;

    if(head==NULL)
    {
      NEW->next=head;
      head = NEW;
    }
    else
    {
      while(cur->next!=NULL)
      {
        cur = cur->next;
      }

      NEW->next = cur->next;
      cur->next = NEW;
    }

    return head;
}

struct Node* reverse(struct Node* head)
{
  if(head==NULL || head->next==NULL)
  {
  	return head;
  } 
  	
  struct Node* second = head->next;
  struct Node* rest = reverse(second);
  second->next = head;
  head->next = NULL;
  return rest;
}

struct node* recursiveReverseLL(struct node* first){

   if(first == NULL) return NULL; // list does not exist.

   if(first->link == NULL) return first; // list with only one node.

   struct node* rest = recursiveReverseLL(first->link); // recursive call on rest.

   first->link->link = first; // make first; link to the last node in the reversed rest.

   first->link = NULL; // since first is the new last, make its link NULL.

   return rest; // rest now points to the head of the reversed list.
}

ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* temp = head->next;
        head->next = NULL;
        
        ListNode* revhead = reverseList(temp);
        temp->next = head;
        
        return revhead;   
    }

ListNode* reverseList(ListNode* head) // Iterative method
    {
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head)
        {
        	next = head->next;
        	head->next = prev;
        	prev = head;
        	head = next;
        }

        return prev;  
    }

void display(struct Node* head)
{
  struct Node* cur = head;
  if(head==NULL)cout<<"EMPTY";
  else
  {
    while(cur!=NULL)
    {
      cout<<cur->val;
      cur = cur->next;
    }
    cout<<endl;
  }
}

ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL )
            return head;
        ListNode* p = head;
        ListNode* q = p->next;
        while(q)
        {
            int temp = p->val;
            p->val = q->val;
            q->val = temp;
            
            p = q->next;
            q = p?p->next:NULL;
            
        }
        
        return head;
        
        
    }

ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL )
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
            
        p->next = swapPairs(q->next);
        q->next = p;
        return q;
         
    }

int main()
{
  struct Node* head = NULL;
  string s;
  cin>>s;

  int n = s.length();
  for(int i=0;i<n;i++)
  {
    head = insert(head,s[i]);
  }
  head = reverse(head);

 display(head);
  return 0;
}
