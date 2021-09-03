//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 30 in 22 : 33 : 50
//title - D_Hanjo.cpp
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
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, m, a, b, dp[N], ans;
void f(int va, int ma, int a, int b){
	if(ma == (1 << (n * m)) - 1){
		ans++;
		return;
	}
	if(va == n * m){
		return;
	}
	if(b != 0LL and ((1LL << va) & ma) == 0LL)
		f(va + 1, ma | (1LL << va), a, b - 1);
	int i = va / m, j = va % m;
	if(a != 0LL and ((1LL << va) & ma) == 0LL){
		if((ma & (1LL << (va + m))) == 0LL and i != n - 1)
			f(va + 1, ma | (1LL << va) | (1LL << (va + m)), a - 1, b);
		if((ma & (1LL << (va + 1))) == 0LL and j != m - 1)
			f(va + 1, ma | (1LL << va) | (1LL << (va + 1)), a - 1, b);
	}
	if(((1LL << va) & ma) != 0LL){
		f(va + 1, ma, a, b);
	}
}
void solve(){
	// fill(dp, dp + N, - 1);
	cin >> n >> m >> a >> b;
	assert(n * m == (a << 1) + b);
	f(0, 0, a, b);
	cout << ans;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}