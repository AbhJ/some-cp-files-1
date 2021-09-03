//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 03 in 20 : 23 : 38
//title - D_Treasure_Hunting.cpp
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
int n, m, k, q, r[N], c[N], b[N], x, pos = 1;vi a[N];
void solve(){
	cin >> n >> m >> k >> q;
	rep(i, 1, k){
		cin >> r[i] >> c[i];
		a[r[i]].pb(a[i]);
	}
	rep(i, 1, n)
		sort(all(a[i]);
	rep(i, 1, q)
		cin >> b[i];
	rep(i, 1, n){
		//collect all treasures in a row
		if(x == 0){
			//going from left to right
			int fir = a[i][0], las = a[i][1];
			int nex_fir = a[i + 1][0];
			int nex = *lower_bound(b + 1, b + 1 + q, nex_fir);
			if(i != n){
				if(nex_fir >= nex and nex >= las)
					ans += las - pos,
					pos = las;
				else{
					vi choices;
					if(a[i + 1].empty() == 0){
						ans += las - pos,
						pos = las;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}