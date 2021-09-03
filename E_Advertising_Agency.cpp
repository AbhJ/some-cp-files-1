//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 15 in 05 : 29 : 49
//title - E_Advertising_Agency.cpp
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
#include <bits/stdc++.h>
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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, k, a[N], dp[N][N], p[N], ma;
// int f(int i, int sum, int k){
// 	if(dp[i][k])
// 		return dp[i][k];
// 	if(k == 0){
// 		if(sum == ma)
// 			return 1;
// 		return 0;
// 	}
// 	int cnt = 0;
// 	rep(j, i + 1, n){
// 		cnt += f(j, sum, k) + f(j, sum + a[j], k - 1);
// 	}
// 	return dp[i][k] = cnt;
// }
int f[N],b[N];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
void solve(){
	cin >> n >> k;
	rep(i, 1, n)
		rep(j, 1, n)
			dp[i][j] = 0;
	rep(i, 1, n)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n)
		p[i] = a[i] + p[i - 1];
	ma = p[n] - p[n - k];
	int ele = a[n - k + 1];
	int g_cnt = upper_bound(a + 1, a + 1 + n, ele) - a;
	// cout << g_cnt;
	g_cnt = n - g_cnt + 1;
	if(g_cnt == 0){
		int tot_cn = 0;
		rep(i, 1, n)
		if(a[i] == a[n])
			tot_cn++;
		cout << C(tot_cn, k);
		return;
	}
	int ele_cnt = k - g_cnt;
	// cout << g_cnt;
	int tot_cnt = 0;
	rep(i, 1, n)
		if(a[i] == ele)
			tot_cnt++;
	cout << C(tot_cnt, ele_cnt);
}
int32_t main()
{
  ibs;cti;
  calc_fact();
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}