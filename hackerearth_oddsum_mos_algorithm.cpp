//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int block = 300;
class Query {
    public:
	int l, r, idx;
	pair<int, int> toPair() const {
		return make_pair(l / block, r*(((l/block) & 1)?-1:1));
	}
};
bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}
vi ans(N);
set<int>z;
int sum_odd,sum_even,s[N];
// int cnt;
int c[N];map<int,int>pos;
vi a;
void add(int x){
    // x=a[x];
    s[c[x]]++;
    if(s[c[x]]&1){
        sum_odd+=s[c[x]]*a[x];
    }
    else{
        sum_odd-=(s[c[x]]-1)*a[x];
    }
}
void rem(int x){
    // x=a[x];
    s[c[x]]--;
    if(s[c[x]]&1){
        sum_odd+=((int)s[c[x]])*a[x];
    }
    else{
        sum_odd-=((int)(s[c[x]]+1))*a[x];
    }
}
void solve(){
    int n;cin>>n;int qu;vi b(n);a=b;
    rep(i,0,n-1)cin>>a[i],b[i]=a[i];
    res(b);
    // for(auto i:b)cout<<i<<" ";
    rep(i,0,b.size()-1)pos[b[i]]=i;
    rep(i,0,n-1)c[i]=pos[a[i]];
    cin>>qu;
    vector<Query>Q(qu);
    rep(i,0,qu-1){
        cin>>Q[i].l>>Q[i].r;
        Q[i].idx=i;
    }
    int cur_l=0,cur_r=-1;
    block=sqrt(qu);
    sort(all(Q));
    for(auto q:Q){
        q.l--,q.r--;
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            rem(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            rem(cur_r);
            cur_r--;
        }
        ans[q.idx]=sum_odd;
    }
    rep(i,0,qu-1)cout<<ans[i];
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}