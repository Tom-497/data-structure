#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<int> str;

    for(int i=0;i<n;i++)
    {
       int t;
       cin>>t;
       str.push_back(t);
    }
    int x,y;

    cin>>x>>y;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if((str[i]>y||str[i]<x)&&flag==0)
        {
            cout<<str[i];
            flag=1;
        }
        else if((str[i]>y||str[i]<x)&&flag==1)
        {
            cout<<" "<<str[i];
        }
    }





    return 0;
}
