//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 11 in 19 : 20 : 21
//title - D_The_Wu.cpp
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
int n, q, m, a[N], k, co[1 << 12];bitset<12> s[N], t;
int dp[1 << 12][1201], pro[1 << 12];
void f(){
	rep(mas, 0, (1 << 12) - 1)if(co[mas] != 0){
		int taka = 0;
		bitset<12>x = bitset<12>(mas) ^ t;
		rep(j, 0, 12 - 1)taka += (x[j] ^ 1) * a[j + 1];
		dp[t.to_ullong()][taka] += co[mas];
	}
	rep(i, 1, 1200)dp[t.to_ullong()][i] += dp[t.to_ullong()][i - 1];
}
void solve(){
	cin >> n >> m >> q;
	rep(i, 1, n)cin >> a[n - i + 1];
	fill(pro, pro + (1 << 12), - 1);
	rep(i, 1, m){
		cin >> s[i];
		co[s[i].to_ullong()]++;
	}
	rep(i, 1, q){
		cin >> t >> k;
		if(pro[t.to_ullong()] == - 1)
			pro[t.to_ullong()] = 1, f();
		cout << dp[t.to_ullong()][k];
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}