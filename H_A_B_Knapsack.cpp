//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 01 in 18 : 53 : 06
//title - H_A_B_Knapsack.cpp
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
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, m, a[N], b[N], taka, cnt, l, s, aa, bb, su;
void f(){
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	reverse(a + 1, a + 1 + n);
	per(i, m, 1)
		b[i] += b[i + 1];
	rep(i, 0, n){
		su += a[i];
		while(l < m and i * aa + (m - l) * bb > s)
			l++;
		if(i * aa + (m - l) * bb <= s)
			cnt = max(cnt, su + b[l + 1]);
	}
}
void solve(){
	cin >> n >> m >> s >> aa >> bb;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, m)
		cin >> b[i];
	f();
	cout << cnt;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}