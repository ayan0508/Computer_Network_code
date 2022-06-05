
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
bool pow_of_two(int n)
{
    return (ceil(log2(n))==floor(log2(n)));
}
int getparity(int n)
{
    int p=0;
    for( p=1; p<n; p++)
    {
        if(pow(2,p)==(n+p+1)||pow(2,p)>(n+p+1))
            {
                break;
            }
    }
    return p;
}
int main()
{
    int n;
    cout<<"enter the size of data you want to write:";
    cin>>n;
    int p = getparity(n);
    int a[n+p+1];
    cout<<"insert data:"<<endl;
    for(int i=1;i<=n+p;i++)
    {
        if(pow_of_two(i))
            a[i]=-1;
        else
            cin>>a[i];
    }
    for(int i=1;i<=n+p;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    senderside(&a[0],n+p);
}
