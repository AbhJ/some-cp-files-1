//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 20 in 17 : 29 : 14
//title - D_Cleaning.cpp
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
const int inf = /*0x3f3f3f3f*/1e17+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], p[N], s[N];
int check(vi a){
	int n = a.size() - 1;
	rep(i, 2, n - 1){
		if(a[i] >= a[i - 1])a[i] -= a[i - 1], a[i - 1] = 0;
		if(a[i] >= a[i + 1])a[i] -= a[i + 1], a[i + 1] = 0;
	}
	if (accumulate(all(a), 0LL) == 0){
		cout << "YES";return 1;
	}
	return 0;
}
void solve(){
	cin >> n;vi z(n + 1);
	rep(i, 1, n)cin >> a[i], z[i] = a[i];
	rep(i, 0, n + 3)p[i] = s[i] = 0;
	if(check(z))return;
	rep(i, 1, n){
		if(a[i] >= p[i - 1])p[i] = a[i] - p[i - 1];
		else p[i] = inf;
	}
	per(i, n, 1){
		if(a[i] >= s[i + 1])s[i] = a[i] - s[i + 1];
		else s[i] = inf;
	}
	rep(i, 1, n - 1){
		swap(a[i], a[i + 1]);
		if(check(vi {0LL, p[i - 1], a[i], a[i + 1], s[i + 2]}))return;
		swap(a[i], a[i + 1]);
	}
	cout << "NO";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}