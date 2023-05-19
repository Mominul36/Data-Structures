#include<bits/stdc++.h>
using namespace std;
int top=-1;
int capacity=10000;
class stac
{
  int a[10000];
public:
  void push(int x);
  void pop();
  void print();
};
int main()
{
    stac s;

    s.pop();
    s.push(1);
    s.push(2);
    s.print();
    s.pop();
    s.print();
    
}
stac :: void push(int x)
  {
      if(top>=capacity-1)
      cout<< "Stack is full"<<endl;
      else
      {
         top++;
          a[top]=x;
      }

}
stac :: void pop()
{
       if(top<0)
        cout<< "stack is empty"<<endl;
       else
         top--;
}
stac :: void print()
{
      for(int i=0;i<=top;i++)
        cout<<a[i]<< " ";
        cout<<endl;
}
