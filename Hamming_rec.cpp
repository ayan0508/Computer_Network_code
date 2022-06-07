#include<bits/stdc++.h>
using namespace std;
bool iserror(int arr[],int l,int n)
{
    int sum=0;
    for(int i=n;i<=l;i+=2*n)
    {
        for(int j=i;j<i+n;j++)
        {
           if(j<=l&&j!=n)
                sum+=arr[j];
        }
    }
    if(sum%2==0)
    {
        if(arr[n]==0)
            return true;
        else
            return false;
    }
    else
    {
        if(arr[n]==1)
            return true;
        else
            return false;       
    }
}

bool isparity(int n)
{
    return (ceil(log2(n))==floor(log2(n)));
}
void check_hamming(int arr[],int l)
{
    int f=0;
    for(int i=1;i<=l;i++)
    {
        if(isparity(i))
        {
            if(iserror(arr,l,i))
               {
                        f=1;
               } 
            else
            {
                f=0;break;
            }
        }
        else
            continue;
    }
    if(f==1)
        cout<<"data correct"<<endl;
    else
        cout<<"data incorrect"<<endl;
}
int main()
{
    string str;
    cin>>str;
    int l = str.size();
    int arr[l];
    for(int i=1; i<=l; i++)
    {
       arr[i]=str[i-1]-'0';
    }
    check_hamming(arr,l);
}