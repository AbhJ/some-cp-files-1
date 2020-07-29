#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
// const int N=300;
const ll M = 1e18; // modulo
 int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
ll div(ll n)
{
    int d[1000001]={0};
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            d[j]++;
    return d[n];
}
double dist(pair<double,double>a,pair<double,double>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
pair<ll,std::vector<int> > mal(std::vector<int> v,int n,int m,int pos){
    for (int i = pos+1; i < n; ++i)
    {
        if(v[i]>v[i-1])v[i]=min(v[i-1],m);
    }
    for (int i = pos-1; i >-1; --i)
    {
        if(v[i]>v[i+1])v[i]=min(v[i+1],m);
    }
    ll ans=0;
    for (int i = 0; i < n; ++i)
    {
        ans+=v[i];
    }
    return {ans,v};
}
// Function to rearrange character of a string 
// so that no char repeat twice 


void solve(){
    ll x,y,a,b,t;cin>>x>>y>>a>>b;
    if(x==y){cout<<0;return;}
    t=(-x+y)/(a+b);if(x+a*t==y-b*t)cout<<t;else cout<<"-1";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}