#include<bits/stdc++.h>
using namespace std;
//sender site
vector<vector<int>> senderside(vector<vector<int>>& v)
{
    vector<vector<int>> send_data;
    vector<int> v1;
    vector<int> col_matrix;
     int sum=0;
    for(int i=0; i<v.size();i++)
    {
        for(int j=0; j<v[i].size();j++)
        {
            
            sum = sum +v[i][j];
        }
        if(sum%2 ==0)
            v[i].push_back(0);
        else
            v[i].push_back(1);
        sum=0;
    }
    for(int i=0; i<v[0].size();i++)
    {
        for(int j=0; j<v.size();j++)
        {
            
            sum = sum +v[j][i];
        }
        if(sum%2 ==0)
            col_matrix.push_back(0);
        else
            col_matrix.push_back(1);
        sum=0;
    }
    v.push_back(col_matrix);
    return send_data;
}

void reciver(vector<vector<int>>& data)
{
    vector<int> row_matrix;
    vector<int> col_matrix;
    int r = data.size()-1;
    int f=0;
    for(int i=0;i<r-1;i++)
    {
        int sum1 =0;
        int sum2=0;
        for(int j=0;j<data[0].size()-1;j++)
            {
                sum1+=data[i][j];
                sum2+=data[j][i];
            }
        if(sum1%2==0)
            {
                if(data[i][r]==0)
                   f=1;
                else
                    {
                       f=0;
                       break;
                    }
            }
        else    
            {
                if(data[i][r]==1)
                    f=1;
                else
                    {
                        f=0;
                        break;
                    }
            }
    }
    if(f==1)
       cout<<"data correct"<<endl;
    else
        cout<<"data incorrect"<<endl;
}
int main()
{
    int r,c;
    vector<vector<int> >v;
    vector<vector<int> >rec;
    cout<<"Enter row and column :"<<endl; 
    cin>>r>>c;  
    cout<<"Enter data :"<<endl;   
    //taking input
    for(int i=0; i<r;i++)
    {
        vector<int> row;
        for(int j=0; j<c;j++)
        {
            int data;
            cin>>data;
            row.push_back(data);
        }
        v.push_back(row);
        row.clear();
    }
   rec= senderside(v);
   reciver(rec);
}
