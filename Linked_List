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
    temp->next=head;
    return temp;

}
node * insertend(node* head, int data)
{
       node * temp=(node *)malloc(sizeof(node));
       node* tail=head;
       temp->data=data;
       temp->next=NULL;
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
node* inputlist()
{
    node* temp=new node;
    long n,d;
    cout<<"Enter number of element: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        temp->data=d;
        temp->next=temp;
    }
    //temp->next=NULL;
    return temp;
}
int main()
{
     node* first,*second,*third;
     first=(node *) malloc(sizeof(node*));
     second= (node *)malloc(sizeof(node*));
     third=(node*)malloc(sizeof(node*));
     first->data=10;
     first->next=second;
     second->data=20;
     second->next=third;
     third->data=30;
     third->next=NULL;
     print(first);
    first=reverse(first);
     print(first);
}
