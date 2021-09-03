//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 01 in 19 : 30 : 13
//title - I_Segment_with_the_Required_Subset.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], taka, l = 1, cnt = inf, ans, last, s, su;bool dp[N][1002];set<int>S;
bitset<N>b(1);
int f(int lef, int rig){
	bitset<1001>b(1);
	rep(i, lef, rig)
		b |= b << a[i];
	return b[s];
}
void solve(){
	cin >> n >> s;
	if(n <= 2000){
		rep(i, 1, n)
			cin >> a[i];
		rep(i, 1, n){
			while(f(l + 1, i) != 0 and l < i)
				l++;
			if(f(l, i) != 0)
				cnt = min(cnt, i - l + 1);
		}
		cout << (cnt == inf ? - 1 : cnt);
	}
	else{
		rep(i, 1, n)
			cin >> a[i];
		rep(i, 1, n){
			b |= b << a[i];
			while((b & (b >> a[l]))[s] != 0 and l < i)
				l++, b = (b & (b >> a[l]));
			if(b[s] != 0)
				cnt = min(cnt, i - l);
		}
		cout << (cnt == inf ? - 1 : cnt);
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}