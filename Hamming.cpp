
#include<bits/stdc++.h>
using namespace std;
void Hamming(int *a,int k,int l,int sum)
{
    for(int i=k;i<=l;i+=2*k)
    {
        for(int j=i;j<i+k;j++)
        {
            if(j<=l&&a[j]!=-1)
                sum+=a[j];
        }
        if(sum%2==0) 
            a[k]=0;
        else
            a[k]=1;
    }
}
void senderside(int *a,int l)
{
   int sum = 0;
    for(int i=1;i<=l;i++)
    {
        if(a[i]==-1)
        {
            Hamming(&a[0],i,l,sum);
        }
    }
      for(int i=1;i<=l;i++)
        cout<<a[i]<<" ";
}
bool find(int n)
{
    return (ceil(log2(n))==floor(log2(n)));
}
    
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        if(find(i))
            a[i]=-1;
        else
            cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    senderside(&a[0],n);
}