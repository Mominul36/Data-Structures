#include<bits/stdc++.h>
using namespace std;

class Queue
{
  int head=0, tail=0;
  int capacity=5;
  int a[5]; // Always 1 space must be empty 
public:
  void enqueue(int x);
  void dequeue();
  void print();
};

int main()
{
    Queue s;

    s.dequeue();
    s.enqueue(4);
    s.print();
    s.enqueue(5);
    s.print();
    s.enqueue(8);
    s.print();
    s.enqueue(34);
    s.print();
    s.enqueue(56);
    s.print();
    s.dequeue();
    s.print();
    s.dequeue();
    s.print();
    s.enqueue(486);
    s.print();


}
void Queue :: enqueue(int x)
  {
      if((tail+1)%capacity==head)
      {
          cout<<"Queue is full"<<endl;
          return;
      }
      a[tail]=x;
      tail= (tail+1)%capacity;

}
void Queue :: dequeue()
{
       if(head==tail)
       {
           cout<< "Queue is empty"<<endl;
           return;
       }
       head= (head+1)%capacity;
}
void Queue :: print()
{
    if(head==tail)
    {
        cout<<endl;
        return;
    }

    if(head<tail)
    {
        for(int i=head;i<tail;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=head;i<capacity;i++)
       cout<<a[i]<<" ";
    for(int i=0;i<tail;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
