#include<bits/stdc++.h>
using namespace std;
string subtract(string& res,string div)
{
    int l= div.size();
    if(res[0]=='0')
        return res;
    for(int i=l;i>=0;i--)
    {
        int p = (int)res[i] ^ (int)div[i];
        res[i] = '0'+p;
    }
    return res;
}
void receverside(string data,string div)
{
    int l1 = data.size();
    int l2 = div.size();
    string res = "";
    string  ch= "";
    res+=data.substr(0,l2);
    for(int i =l2;i<=l1;i++)
    {
       res =subtract(res,div);
       if(res[0]=='0')
       {
           res.erase(0,1);
            if(i<=data.length()-1)
                {
                    res+=data[i];
                } 
       }
       else
        continue;
    }
    cout<<res;
    int f=0;
    for(int i=0;i<res.length();i++)
    {
        cout<<res[i];
        if(res[i]=='0')
            f=1;
        else
            {
                cout<<i<<endl;
                cout<<"element id"<<res[i]<<endl;
                f=0;break;
            }
    }
    if(f==1)
        cout<<"data correct";
    else
        cout<<"data incorrect";
}
int main()
{
    string data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    string div;
    cout<<"Enter the divisor"<<endl;
    cin>>div;
    receverside(data,div);
}
