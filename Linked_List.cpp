#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node* insertbegin(node * head, int data)
{
    node * temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    return temp;

}
node * insertend(node* head, int data)
{
       node * temp=(node *)malloc(sizeof(node));
       temp->data=data;
       temp->next=NULL;
       node* tail=head;

       if(tail==NULL)
        return temp;
        while(tail!=NULL)
        {
            if(tail->next==NULL)
            {
                tail->next=temp;
                return head;
            }
            tail=tail->next;
        }
}
node * insertbetween(node* head,int pos, int data)
{
      node * temp=(node *)malloc(sizeof(node));
       node* front=head;
       node * back=(node *)malloc(sizeof(node));
       temp->data=data;
       temp->next=NULL;
       if(head==NULL)
        return temp;
      int index=0;
        while(1)
        {
            if(index==pos-1)
            {
                back=front->next;
                front->next=temp;
                temp->next=back;
                return head;
            }
            front=front->next;
            index++;
        }
}
node* removepos(node* head,int pos)
{
    node* front=head;
    node * back=(node *)malloc(sizeof(node));
    if(head==NULL)
        return head;
    if(pos==0)
    {
       front=front->next;
       return front;
    }
    int index=0;
    while(1)
    {
        if(index==pos-1)
        {
            back=front->next;
            back=back->next;
            front->next=back;
            return head;
        }
        front=front->next;
        index++;
    }

}
node* removevalue(node* head,int value)
{
    node* front=head;
     node * res=(node *)malloc(sizeof(node));
    if(head==NULL)
        return head;
    if(front->data==value)
    {
        front=front->next;
        return front;
    }
    while(1)
    {
        if(front->data==value)
        {
            front=front->next;
            res->next=front;
           return head;
        }
        res=front;
        front=front->next;
    }

}
node* removebegin(node* head)
{
    head=head->next;
    return head;
}
node* removeend(node* head)
{
    node * res=head;
    node* tail=head;
    if(head==NULL)
      return head;
    while(1)
    {
        if(tail->next==NULL)
        {
         res->next=NULL;
         return head;
        }
        res=tail;
        tail=tail->next;
    }
}
node* reverse(node* head)
    {
        node* current = head;
        node *front = NULL, *back = NULL;

        while (current != NULL) {
            back = current->next;
            current->next = front;
            front = current;
            current = back;
        }
       return front;
    }
void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
       cout<< temp->data<< " ";
       temp=temp->next;
    }
    cout<<endl;
}
node* input(int n)
{
   node *head=NULL,*current=NULL,*temp=NULL;
    current=head;
    int d;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        temp = (node *)malloc(sizeof(node*));
        temp->data=d;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
           current=temp;
           continue;
        }

        current->next=temp;
        current=current->next;
    }
return head;
}
int main()
{
   node *head=NULL;
   int n;
   cout<< "Enter number of element: ";
   cin>>n;
   cout<< "Enter "<<n<< " number: ";
   head=input(n);
   cout<< "After input = ";
   print(head);

   head= insertend(head,100); //value=100
   cout<< "After insert end: ";
   print(head);

   head= insertbegin(head,200);//value=200
   cout<< "After insert begin: ";
   print(head);

   head= insertbetween(head,5,10);// position=5(start from 0) and value=10
   cout<< "After insert between: ";
   print(head);

   head= removebegin(head);
   cout<< "After remove begin: ";
   print(head);

   head= removeend(head);
   cout<< "After remove end: ";
   print(head);

   head= removepos(head,4); //position=4(start from 0)
   cout<< "After remove a value in a specific position: ";
   print(head);

   head= removevalue(head,9); //value=9
   cout<< "After remove a specific value: ";
   print(head);

   head= reverse(head);
   cout<< "After reverse: ";
   print(head);
}
