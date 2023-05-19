#include<bits/stdc++.h>
using namespace std;
int top=-1;
int capacity=10000;
class Stack
{
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
Stack :: void push(int x)
  {
      if(top>=capacity-1)
      cout<< "Stack is full"<<endl;
      else
      {
         top++;
          a[top]=x;
      }

}
Stack :: void pop()
{
       if(top<0)
        cout<< "stack is empty"<<endl;
       else
         top--;
}
Stack :: void print()
{
      for(int i=0;i<=top;i++)
        cout<<a[i]<< " ";
        cout<<endl;
}
