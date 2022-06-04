#include<bits/stdc++.h>
using namespace std;
string subtract(string res,string div)
{
    if(res[0]=='0')
    {
        return res;
    }
    else
    {
        for(int i=0;i<res.length();i++)
        {
            int p = (int)res[i]^(int)div[i];
            res[i]='0'+p;
            p=0;
        }
    }
    return res;
}
void senderside(string data, string div)
{
    int l = div.length();
    string res;
    res+= data.substr(0, l);
    for(int i = l; i <= data.length();i++)
    {
        res = subtract(res,div);
        if(res[0]=='0')
        {
            res.erase(0,1);
            //cout<<"in normal res:"<<res<<endl;
            if(i<=data.length()-1)
                {
                    res+=data[i];
                   // cout<<"res in if vlock:"<<res<<endl;
                }
            else
                break;
        }
        else
        {
            continue;
            //cout<<"res in else vlock:"<<res<<endl;
        }
    }
    cout<<endl;
    cout<<res<<endl;
}
int main()
{
    string data;
    cout<<"Enter data:"<<endl;
    cin>>data; 
    string div;
    cout<<"Enter div:"<<endl;
    cin>>div;
    for(int i=0;i<div.size()-1;i++)
        data +='0';
    cout<<data;
    senderside(data,div);
}
