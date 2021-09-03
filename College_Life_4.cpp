//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 10 in 01 : 23 : 09
//title - College_Life_4.cpp
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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, e, h, a, b, c, koita_choco, koita_om, ans = inf;
vi A(N);
void solve(){
	cin >> n >> e >> h >> a >> b >> c;
	rep(koita_milkshake, 0, n){
		//koita_milkshake is number of milk shake
		int cnt_om = lower_bound(A.begin(), A.begin() + n + 2, 2 * n - e - 2 * koita_milkshake) - A.begin();
		int cnt_cc = upper_bound(A.begin(), A.begin() + n + 2, h - 3 * koita_milkshake) - A.begin() - 1;
		if(cnt_cc < cnt_om or cnt_om == n + 1 or (cnt_cc == n + 1 and cnt_cc - h > - 3 * koita_milkshake))
			continue;
		koita_choco = n - koita_milkshake;
		if(c > a)
			//taka omlette
			koita_choco = min(koita_choco, cnt_om);
		else
			//take chocolate cake
			koita_choco = min(koita_choco, cnt_cc);
		koita_om = n - koita_milkshake - koita_choco;
		if(h < koita_choco + 3 * koita_milkshake)
			continue;
		if(2 * koita_milkshake + e < 2 * n - koita_choco)
			continue;
		//sufficient quanitity are present
		ans = min(ans, a * koita_om + b * koita_milkshake + c * koita_choco);
	}
	if(ans == inf)cout << - 1;
	else cout << ans;
	ans = inf;
}
int32_t main()
{
  ibs;cti;
  iota(all(A), 0);
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}