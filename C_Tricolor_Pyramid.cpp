//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 18 in 20 : 49 : 10
//title - C_Tricolor_Pyramid.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const ll M = 3; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n; string s, tmp;
int f[N],b[N];
int mul(int a,int b){
  return (((a%M)*(b%M)) + M)%M;
}
int add(int a,int b){
  return (((a%M)+(b%M)) + M)%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=(b*b)%M, p/=2)
    if(p&1)
      r=(r*b)%M;
  return r;
}
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
// int C(int n,int r){
//   assert(n<N);assert(r<N);
//   if(r>n)return 0;
//   return (f[n]*mul(b[r],b[n-r])%M)%M;
// }
int C(int x,int y){
	if(x<y) return 0;
	if(x<=2){
		if(x==2 and y==1) return 2;
		return 1;
	}
	return C(x/3,y/3) * C(x%3,y%3) % 3;
}
int a[N], ans, mg = - 1;
void solve(){
	cin >> n >> s;
	rep(i, 0, n - 1){
		if(s[i] == 'B')
			a[i] = 0;
		if(s[i] == 'W')
			a[i] = 1;
		if(s[i] == 'R')
			a[i] = 2;
	}
	rep(i, 0, n - 1){
		ans = add(ans, mul(a[i], C(n - 1, i)));
		// mg = - mg;
	}
	if(n & 1 ^ 1)
		ans = mul(ans, - 1);
	// cout << ans;
	if(ans == 0LL)
		cout << "B";
	if(ans == 1LL)
		cout << "W";
	if(ans == 2LL)
		cout << "R";
}
int32_t main()
{
  ibs;cti;
//   calc_fact();
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}