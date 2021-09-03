//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 10 in 01 : 12 : 16
//title - F_New_Year_s_Puzzle.cpp
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
#define rep(i,a,b) for (int i = a; i <= b; i += 2)
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
int n, m, r[N], c[N], pos[N];
static bool cmp(int i, int j){
	return c[i] < c[j];
}
void solve(){
	cin >> n >> m;
	rep(i, 1, m)cin >> r[i] >> c[i], i--;
	if(abs(2 * n - m) & 1 != 0){cout << "NO";return;}
	iota(pos + 1, pos + 1 + m, 1);
	sort(pos + 1, pos + 1 + m, cmp);
	rep(i, 1, m){
		int j = i + 1;
		int l = pos[i], R = pos[j], last = pos[i - 1];
		if(i == 1 or (c[l] != c[last]))
			if((r[l] + c[l]) % 2 != ((r[R] + c[R]) % 2))
				continue;
		cout << "NO";return;
	}
	cout << "YES";return;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}