#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
// ll dp[1000][1000];
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
//using manacher's algorithm
void solve(){
      int n;cin>>n;std::vector<int> v(n);
      for (int i = 0; i < n; ++i)cin>>v[i];
      int x=v[0];int i=n-1;
      for (int j = n-1; j > 0; --j)
      {
        if(v[j]>=x)swap(v[i],v[j]),i--;
      }
      swap(v[i],v[0]);
      for (int i = 0; i < n; ++i)
      {
        cout<<v[i]<<" ";
      }
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}