#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin()+1, x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const double Pi = 3.14159265;
#define F first
#define S second
void solve(){
  int n,k;cin>>n>>k;
  vvi a(n+10,vi(n+10,0));
  rep(i,0,n-1)rep(j,0,n-1)if(k)a[j][(i+j)%n]=1,k--;
  int mar=-inf,mir=inf,mac=-inf,mic=inf;
  rep(i,0,n-1){
    int cnt=0,c=0;
    rep(j,0,n-1)cnt+=a[i][j],c+=a[j][i];
    mir=min(mir,cnt);
    mar=max(mar,cnt);
    mic=min(mic,c);
    mac=max(mac,c);
  }
  cout<<(mar-mir)*(mar-mir)+(mac-mic)*(mac-mic)<<"\n";
  rep(i,0,n-1){
    rep(j,0,n-1)cout<<a[i][j];
    cout<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();}
  return 0;
}