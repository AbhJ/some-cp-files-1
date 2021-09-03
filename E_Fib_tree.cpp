//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 02 in 01 : 20 : 55
//title - E_Fib_tree.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int f[N], n, m, x, y, F = 1, cnt, su[N];set<int>s;set<int>a[N];pii p{- 1, - 1};
int fi(int u, int p = - 1){
	int c = 1;
	for(auto &i: a[u])if(p != i){
		c += fi(i, u);
	}
	// if(u == 1)
	// 	cout << c;
	return c;
}
void fib(int u, int P = - 1){
	su[u] = 1;
	for(auto &i: a[u])if(P != i){
		fib(i, u);
		if(s.count(su[i]) and s.count(cnt - su[i])){
			// cout << i << " " << u << "\n";
			p = pii{i, u};
		}
		su[u] += su[i];
	}
}
void ok(int u){
	cnt = fi(u);
	// cout << cnt;
	if(F == 0)
		return;
	fib(u);
	if(cnt == 1)
		return;
	if(s.count(cnt) == 0 or p == pii{- 1, - 1})
		F = 0;
	if(F == 0)
		return;
	a[p.F].erase(p.S);
	a[p.S].erase(p.F);
	pii pp = p;
	p = pii{- 1, - 1};
	ok(pp.F);
	ok(pp.S);
	cnt = 0;
}
void solve(){
	cin >> n;m = n - 1;
	f[0] = f[1] = 1;
	rep(i, 2, n)
		f[i] = f[i - 1] + f[i - 2],
		s.insert(f[i]);
	s.insert(1);
	rep(i, 1, m){
		cin >> x >> y;
		a[x].insert(y);
		a[y].insert(x);
	}
	ok(1);
	if(F)
		cout << "YES";
	else
		cout << "NO";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}