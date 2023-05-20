// Use c language
#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
    int data;
    Node *next;
};
Node* input_list(int n);
Node* creat_list(int a[],int n);
Node* push_back(Node *head, int n);
Node* push_front(Node* head, int n);
Node* insert_aftervalue(Node* head,int value,int n);
Node* insert(Node* head,int index,int n);//index start from zero
Node* pop_back(Node* head);
Node* pop_front(Node* head);
Node* erase_value(Node* head, int value);
Node* erase(Node* head, int index);//index start from zero
int size(Node* head);
int empty(Node* head);
int max(Node* head);
int min(Node* head);
int sum(Node* head);
int front(Node* head);
int back(Node* head);
void swap(Node **first, Node **second);
void print(Node* head);

int main()
{
    Node* head=NULL,*tail=NULL;
    int a[]={1,2,3,4,5},b[]={10,20,30,40,50},n;
    head = creat_list(a,5);
    tail=creat_list(b,5);
    printf("After creat list: ");
    print(head);
    head = push_back(head,7);
    printf("After push back: ");
    print(head);
    head = push_front(head,0);
    printf("After push front: ");
    print(head);
    head = insert_aftervalue(head,5,6);
    printf("After insert aftervalue: ");
    print(head);
    head = insert(head,2,100);
    printf("After insert at particular index: ");
    print(head);
    head = pop_back(head);
    printf("After pop back: ");
    print(head);
    head = pop_front(head);
    printf("After pop front: ");
    print(head);
    head = erase_value(head,100);
    printf("After erase a value: ");
    print(head);
    head = erase(head,3);
    printf("After erase a particular indexed value: ");
    print(head);
    n=size(head);
    printf("Size of list: %d\n",n);
    n=max(head);
    printf("Maximum element of list: %d\n",n);
    n=min(head);
    printf("Minimum element of list: %d\n",n);
    n=sum(head);
    printf("Sum of list: %d\n",n);
    n=front(head);
    printf("First element of list: %d\n",n);
    n=back(head);
    printf("Last value of list: %d\n",n);
    n=empty(head);
    printf("List is empty or not: %d\n",n);
    printf("\n\nAfter swap:\n");
    printf("Head = ");
    print(head);
    printf("Tail = ");
    print(tail);
    swap(&head,&tail);
    printf("\n\nBefore swap:\n");
    printf("Head = ");
    print(head);
    printf("Tail = ");
    print(tail);

}

Node* input_list(int n)
{
    Node* head,*current;
    int d;
    head = (Node*)malloc(sizeof(Node));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d);
        if(i==0)
        {
           head->data=d;
           head->next=NULL;
           current=head;
        }
        else
        {
            Node* temp;
            temp= (Node*)malloc(sizeof(Node));
            temp->data=d;
            temp->next=NULL;
            current->next=temp;
            current=current->next;
        }

    }
    return head;
}
Node* creat_list(int a[],int n)
{
    Node* head,*current;
    head= (Node*)malloc(sizeof(Node));
    head->data=a[0];
    head->next=NULL;
    current=head;
    for(int i=1;i<n;i++)
    {
        Node* temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=a[i];
        temp->next=NULL;
        current->next=temp;
        current=current->next;
    }
    return head;
}
Node* push_back(Node *head, int n)
{
    Node *temp,*tail;
       temp=(Node*)malloc(sizeof(Node));
        temp->data=n;
        temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        tail = head;
         while(tail->next!=NULL)
         {
             tail=tail->next;
         }
         tail->next=temp;
    }
    return head;
}
Node* push_front(Node* head, int n)
{
    Node* temp;
    temp= (Node*)malloc(sizeof(Node));
    temp->data=n;
    temp->next=head;
    return temp;
}
Node* insert_aftervalue(Node* head,int value,int n)
{
   Node* temp,*current,*tail;
   current=head;
   temp=(Node*)malloc(sizeof(Node));
   temp->data=n;
   temp->next=NULL;
   while(current->data!=value)
   {
       current=current->next;
   }
   tail=current->next;
   current->next=temp;
   temp->next=tail;
   return head;
}
Node* insert(Node* head,int index,int n)
{
    if(index==0)
    {
        Node* temp;
        temp= (Node*)malloc(sizeof(Node));
        temp->data=n;
        temp->next=head;
        return temp;
    }
    Node* temp,*current,*tail;
   current=head;
   temp=(Node*)malloc(sizeof(Node));
   temp->data=n;
   temp->next=NULL;
   int i=0;
   while(i!=index-1)
   {
       current=current->next;
       i++;
   }
   tail=current->next;
   current->next=temp;
   temp->next=tail;
   return head;
}
Node* pop_back(Node* head)
{
    Node* current,*temp=NULL;
    current=head;
    if(size(head)==1)
        return temp;
    while(1)
    {
        temp=current->next;
        if(temp->next==NULL)
            break;
        current=current->next;
    }
    current->next=NULL;
    return head;
}
Node* pop_front(Node* head)
{
    head=head->next;
    return head;
}
Node* erase_value(Node* head, int value)
{
    if(head->data==value)
    {
         head=head->next;
         return head;
    }
    Node* current,*tail;
    current=head;
    while(current->next!=NULL)
    {
       tail=current->next;
       if(tail->data==value)
            break;
       current=current->next;
    }
    tail=tail->next;
    current->next=tail;
    return head;
}
Node* erase(Node* head, int index)
{
    if(index<0 || index>=size(head))
        return head;
    if(index==0)
    {
        head=head->next;
        return head;
    }
    Node* current,*tail;
    current=head;
    int i=0;
    while(i!=index-1)
    {
        current=current->next;
        i++;
    }
    tail=current->next;
    tail=tail->next;
    current->next=tail;
    return head;
}
int size(Node* head)
{
    int n=0;
    while(head!=NULL)
    {
        n++;
        head=head->next;
    }
    return n;
}
int empty(Node* head)
{
    if(size(head)==0)
        return 1;
    return 0;
}
int max(Node* head)
{
    int max_value=head->data;
    while(head!=NULL)
    {
        if(head->data>max_value)
            max_value=head->data;
        head=head->next;
    }
    return max_value;
}
int min(Node* head)
{
    int min_value=head->data;
    while(head!=NULL)
    {
        if(head->data<min_value)
            min_value=head->data;
        head=head->next;
    }
    return min_value;
}
int sum(Node* head)
{
    int sum=0;
    while(head!=NULL)
    {
        sum+=head->data;
        head=head->next;
    }
    return sum;
}
int front(Node* head)
{
    return head->data;
}
int back(Node* head)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    return head->data;
}
void swap(Node **first, Node **second)
{
   Node* temp;
   temp=*first;
   *first=*second;
   *second=temp;
}
void print(Node* head)
{
    Node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}









// Using cpp
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
