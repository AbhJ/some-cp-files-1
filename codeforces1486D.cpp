//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 20 in 05 : 06 : 52
//title - D_Max_Median.cpp
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, k, a[N], cnt[N], cnt2[N], l, r, m;
int f(int v){
	rep(i, 1, n){
		cnt[i] = cnt[i - 1] + (a[i] >= v ? 1 : - 1);
		cnt2[i] = min(cnt2[i - 1], cnt[i]);
		if(i >= k and cnt[i] - cnt2[i - k] > 0){
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin >> n >> k;
	rep(i, 1, n)cin >> a[i];
	l = 1, r = n + 1;
	while(r - l > 1){
		m = ((l + r) >> 1);
		if(f(m))
			l = m;
		else
			r = m;
	}
	cout << l;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}