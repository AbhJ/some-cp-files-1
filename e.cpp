#include <iostream>
#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define mp make_pair
using namespace std;

int32_t main() {
// your code goes here
int t,x=1;
cin>>t;
//cout<<fin(5,2)<<"\n";
while(t--)
{
 //cout<<"Case #"<<x++<<":\n";
int n,m,i,j,k;
cin>>n;
if(n==1)
{
   cout<<"9\n";
   continue;
}
if(n==2)
{
   cout<<"98\n";
   continue;
}
int x=8;
cout<<"98";
for(i=3;i<=n;i++)
{
   cout<<(x+1)%10;
   x=(x+1)%10;
}
cout<<"\n";
 }


return 0;
}