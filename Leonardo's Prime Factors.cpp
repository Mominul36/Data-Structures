#include<iostream>
using namespace std;
int fun(long long n)
{
  long long a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
  long long sum=1;
  if(n==1)
  return 0;
  if(n>=2 && n<=5)
  return 1;
  if(n>=614889782588491410)
  return 15;
  for(int i=0;i<16;i++)
  {
    sum=sum*a[i];
    if(sum>n)
    return i;
  }
return 0;
}
int main()
{
    
       long long n;
       long t;
       cin>>t;
       for(long i=1;i<=t;i++)
       {
          cin>>n;
          cout<<fun(n)<<endl;
       }

}
