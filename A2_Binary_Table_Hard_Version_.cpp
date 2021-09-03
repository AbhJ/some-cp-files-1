//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 28 in 10 : 50 : 28
//title - A2_Binary_Table_Hard_Version_.cpp
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
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m;char a[N][N];
void solve(){
	cin >> n >> m;
	rep(i, 1, n)rep(j, 1, m)cin >> a[i][j];
	vvi ans;
	rep(i, 1, n - 2)
		rep(j, 1, m - 1){
			if(a[i][j] == '1'){
				ans.pb(vi{i, j, i + 1, j, i + 1, j + 1});
				a[i + 1][j] = '1' + '0' - a[i + 1][j];
				a[i + 1][j + 1] = '1' + '0' - a[i + 1][j + 1];
				a[i][j] = '1' + '0' - a[i][j];
			}
		if(a[i][m] == '1'){
			ans.pb(vi{i, m, i + 1, m, i + 1, m - 1});
			a[i + 1][m - 1] = '1' + '0' - a[i + 1][m - 1];
			a[i + 1][m] = '1' + '0' - a[i + 1][m];
			a[i][m] = '1' + '0' - a[i][m];
		}
	}
	rep(j, 1, m - 1){
		if(a[n][j] == '1' and a[n - 1][j] == '1'){
			ans.pb(vi{n, j, n - 1, j, n, j + 1});
			a[n][j] = '1' + '0' - a[n][j];
			a[n][j + 1] = '1' + '0' - a[n][j + 1];
			a[n - 1][j] = '1' + '0' - a[n - 1][j];
		}
		if(a[n][j] == '1' and a[n - 1][j] == '0'){
			ans.pb(vi{n, j, n - 1, j + 1, n, j + 1});
			a[n][j] = '1' + '0' - a[n][j];
			a[n][j + 1] = '1' + '0' - a[n][j + 1];
			a[n - 1][j + 1] = '1' + '0' - a[n - 1][j + 1];
		}
		if(a[n][j] == '0' and a[n - 1][j] == '1'){
			ans.pb(vi{n - 1, j, n - 1, j + 1, n, j + 1});
			a[n - 1][j] = '1' + '0' - a[n - 1][j];
			a[n][j + 1] = '1' + '0' - a[n][j + 1];
			a[n - 1][j + 1] = '1' + '0' - a[n - 1][j + 1];
		}
	}
	if(a[n - 1][m] == '1' and a[n][m] == '1'){
		ans.pb(vi{n - 1, m - 1, n - 1, m, n, m - 1});
		ans.pb(vi{n - 1, m - 1, n, m, n, m - 1});
	}
	if(a[n - 1][m] == '0' and a[n][m] == '1'){
		ans.pb(vi{n - 1, m - 1, n, m - 1, n, m});
		ans.pb(vi{n - 1, m - 1, n - 1, m, n, m});
		ans.pb(vi{n - 1, m, n, m - 1, n, m});
	}
	if(a[n - 1][m] == '1' and a[n][m] == '0'){
		ans.pb(vi{n - 1, m - 1, n - 1, m, n, m - 1});
		ans.pb(vi{n - 1, m - 1, n - 1, m, n, m});
		ans.pb(vi{n - 1, m, n, m - 1, n, m});
	}
	cout << ans.size() << "\n";
	for(auto &i: ans){
		for(auto &j: i)cout << j << " ";
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();}
  return 0;
}