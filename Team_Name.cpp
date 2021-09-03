//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 08 in 11 : 09 : 38
//title - Team_Name.cpp
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
using vi = std::vector<bool>;
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
map<string, string> pre;int n, ans;string S[N];
int f(string x, string y){
	int cnt = 0;
	vi F(26);
	rep(i, 1, (int)x.size())
		F[x[i - 1] - 'a'] = 1;
	rep(i, 1, (int)y.size())
		F[y[i - 1] - 'a'] = 1;
	return accumulate(all(F), 0LL);
}
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> S[i];
	pre.clear();
	rep(i, 1, n){
		string t = S[i].substr(1);
		pre[t] += S[i][0];
	}
	for(auto it = pre.begin(); it != prev(pre.end()); it = next(it))
		for(auto jt = next(it); jt != pre.end(); jt = next(jt))
			ans += ((f(it -> S, jt -> S) - (it -> S).size()) * (f(it -> S, jt -> S) - (jt -> S).size()) << 1);
	cout << ans;ans = 0;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}