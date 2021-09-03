//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 01 in 16 : 44 : 38
//title - F_Card_Substrings.cpp
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
string s, t;int n, m, r, taka, cnt, ans, last = - 1, f[26];
int g(){
	rep(j, 0, 25)
		if(f[j] < 0)
			return 1;
	return 0;
}
void FF(){
	fill(f, f + 26, 0LL);
	rep(i, 0, m - 1)
		f[t[i] - 'a']++;
	f[s[0] - 'a']--;
	rep(i, 0, n - 1){
		while(r < n - 1){
			f[s[r + 1] - 'a']--;
			if(g()){
				f[s[r + 1] - 'a']++;
				break;
			}
			r++;
		}
		if(g() == 0)
			cnt += r - i + 1LL;
		f[s[i] - 'a']++;
	}
	return;
}
void solve(){
	//ab ab ac ca ba ba bac cab + 7
	cin >> n >> m >> s >> t;
	FF();
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