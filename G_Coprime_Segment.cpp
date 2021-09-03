//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 31 in 17 : 38 : 12
//title - G_Coprime_Segment.cpp
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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/3e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], r, cnt = inf;
int sp[N][62];
int f(int l, int r){
	int j = log2(r - l + 1LL);
	return __gcd(sp[l][j], sp[r - (1LL << j) + 1LL][j]);
}
void solve(){
	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i],
		sp[i][0] = a[i];
	rep(j, 1, 61)
		for(int i = 0; i + (1LL << j) <= n; i++)
			sp[i][j] = __gcd(sp[i][j - 1LL], sp[i + (1LL << (j - 1LL))][j - 1LL]);
	rep(i, 0, n - 1){
		while(r < n and f(i, r) != 1)
			r++;
		if(r == n)
			continue;
		if(f(i, r) == 1)
			cnt = min(cnt, r - i + 1LL);
		if(r <= i)
			r = i + 1;
	}
	cout << (cnt != inf ? cnt : - 1);
	return;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}