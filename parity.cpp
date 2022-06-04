#include<bits/stdc++.h>
using namespace std;
vector<int> evenparity(vector<int>& v)
{
    int n = v.size();
    int sum =0;
    for(int i = 0; i < n; i++)
        sum +=v[i];
    if(sum%2==0)
        v.push_back(0);
    else
        v.push_back(1);
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    return v;
}
vector<int> oddparity(vector<int>& v)
{
    int n = v.size();
    int sum =0;
    for(int i = 0; i < n; i++)
        sum +=v[i];
    if(sum%2==0)
        v.push_back(1);
    else
        v.push_back(0);
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    return v;
}
void checkoddparity(vector<int>& v1)
{
    int n = v1.size();
        int sum =0;
    for(int i = 0; i < n; i++)
        sum +=v1[i];
    if(sum%2==0)
        cout<<" Data pod mariecha"<<endl;
    else
        cout<<"thik acha"<<endl;
}
void checkevenparity(vector<int>& v1)
{
    int n = v1.size();
        int sum =0;
    for(int i = 0; i < n; i++)
        sum +=v1[i];
    if(sum%2==0)
        cout<<"thik acha"<<endl;
    else
        cout<<" Data pod mariecha"<<endl;
}
int main()
{
    int c,n;
    cout<<"enter the lenth data word"<<endl;
    cin>>n;
    vector<int> v;
    vector<int>send_data;
    cout<<"enter the data word"<<endl;
    for(int i=0; i<n; i++)
        {
            int data;
            cin>>data;
            v.push_back(data);
        }
    for(int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
    while(1)
    {
        cout<<endl;
        cout<<"Enter The choice if you want"<<endl;
        cout<<" 1.oddparity \n 2.evenparity\n 3 .check-oddparity\n4.check-evenparity\n5.Exit\n";
        cin>>c;
        switch(c)
        {
            case 1:
                send_data = oddparity(v);
                break;
            case 2:
               send_data = evenparity(v);
                break;
            case 3:
                checkoddparity(send_data);
                break;
            case 4:
                checkevenparity(send_data);
                break;
            case 5:
                exit(0);
        }
    }

}