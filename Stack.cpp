#include<bits/stdc++.h>
using namespace std;

class Stack
{
  int top=-1;
  int capacity=10000;
  int a[10000];
public:
  void push(int x);
  void pop();
  void print();
};

int main()
{
    Stack s;

    s.pop();
    s.push(1);
    s.push(2);
    s.print();
    s.pop();
    s.print();

}
void Stack :: push(int x)
  {
      if(top>=capacity-1)
      cout<< "Stack is full"<<endl;
      else
      {
         top++;
          a[top]=x;
      }

}
void Stack :: pop()
{
       if(top<0)
        cout<< "stack is empty"<<endl;
       else
         top--;
}
void Stack :: print()
{
      for(int i=0;i<=top;i++)
        cout<<a[i]<< " ";
        cout<<endl;
}
