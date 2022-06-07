#include<bits/stdc++.h>
using namespace std;
String add(string& res,string str)
{
    int c=0;
    for(int i=res.length()-1;i>=0;i--)
    {
        if(c==0)
        {
            if(res[i]=='0'&&str[i]=='0')
            {
                res[i]='0';
                c=0;
            }
            else if(res[i]=='1'&&str[i]=='1')
            {
                res[i]='0';
                c=1;
            }
            else 
            {
                res[i]='1';
                c=0;
            }
        }
        else
        {
          if(res[i]=='0'&&str[i]=='0')
            {
                res[i]='1';
                c=0;
            }
            else if(res[i]=='1'&&str[i]=='1')
            {
                res[i]='1';
                c=1;
            }
            else 
            {
                res[i]='0';
                c=1;
            }
        }
    }
    if(c==1)
    {
        for(int i=res.length()-1;i>=0;i--)
        {
            if(c==1)
            {
                if(res[i]=='1')
                {
                    res[i]='0';
                    c=1;
                }
                else
                    {
                        res[i]='1';
                        c=0;
                    }
            }
        }
    }
    else
    {
        return res;
    }
    cout<< res;
    return res;
}
void reciver_side(string data,int block)
{
    int l = data.length();
    string res="";
    string str="";
    string finel="";
    res+=data.substr(0,block);
    for(int i=block;i<l;i+=block) 
    {
        for(int j=i;j<i+block;j++)
            str+=data[j];
        finel=add(res,str);
        str.clear();
    }
    cout<<"finel:"<<finel<<endl;
    return finel;
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
    string data;
    string check;
    int block;
    cin>>data>>block;
    int f=0;
   check= onecom(reciver_side(data,block));
   for(int i=0;i<check.length();i++)
   {
       if(check[i]=='0')
            f=1;
        else
            {
                f=0;
                break;
            }
   }
   if(f==0)
        cout<<"data is correct"<<endl;
    else
        cout<<"incorrect";

}