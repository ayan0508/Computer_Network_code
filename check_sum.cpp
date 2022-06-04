#include<bits/stdc++.h>
using namespace std;
string add(string str,string res)
{
    int c=0;
    int l = str.length();
    string temp="";
    for(int i=str.size()-1;i>=0;i--)
    {
        if(c==0)
        {
            if(str[i]=='1'&&res[i]=='0')
                {
                    temp+='1';
                    c=0;
                }
                else if(str[i]=='0'&&res[i]=='1')
                {
                    temp+='1';
                    c=0;
                    
                }
                else if(str[i]=='0'&&res[i]=='0')
                {
                    temp+='0';
                    c=0;
                   
                }
                else
                {
                    temp+='0';
                    c=1;
                 
                }
        }
        else
        {
            if(str[i]=='1'&&res[i]=='0')
            {
                        temp+='0';
                        c=1;
                       
            }
            else if(str[i]=='0'&&res[i]=='1')
            {
                temp+='0';
                c=1;
               
            }
            else if(str[i]=='0'&&res[i]=='0')
            {
                temp+='1';
                c=0;
              
            }
            else
            {
                temp+='1';
                c=1;
             
            }
        }
    }
    reverse(temp.begin(), temp.end());
    res.clear();
    if(c==1 &&temp.length()==l)
    {    
        for(int i=temp.length()-1;i>=0;i--)
        {
            if(c==1)
            {
                if(temp[i]=='1')
                {
                    c=1;
                    res+='0';
                }
                else
                {
                    c=0;
                    res+='1';
                }
            }
            else
                res+=temp[i];
        }
    }    
    reverse(res.begin(), res.end());   
   // cout<<res<<endl;  
   return res;  
   // cout<<"carry:"<<c;
}
string senderside(string str,int n)
{
    string res="";
    string ay="";
    int l = str.size();
    //int c = l/n;
    string str1;
        res += str.substr(0,n);
        //cout<<res<<endl;
        for(int i=n;i<l;i+=n)
        {
            for(int j=i;j<i+n;j++)
            {
                str1 += str[j];                    
            }
            ay = add(str1,res);
          // cout<<str1<<endl;
            str1.clear();
        }
    return ay;
}
string onescom(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='1')
            str[i]='0';
        else
            str[i]='1';
    }
    cout<<"compliment is:"<<str<<endl;
    return str;
}
int main()
{
    string str="";
    string send_data="";
    cin>>str;
    int n;
    cout<<"Enter the block size"<<endl;
    cin>>n;
    send_data = str;
    string p = senderside(str,n);
    send_data += onescom(p);
    cout<<send_data<<endl;
}