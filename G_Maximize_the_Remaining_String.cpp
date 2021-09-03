//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 27 in 17 : 18 : 35
//title - G_Maximize_the_Remaining_String.cpp
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
#include <bits/stdc++.h>
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, ans, taka, koita, done[26], f[26];vector<set<int>>s;
string S, t;
void solve(){
	cin >> S;s.clear();
	if(s.size() != 26)
		s.resize(26);
	n = S.length();
	rep(i, 0, n - 1)
		s[S[i] - 'a'].insert(i),
		done[S[i] - 'a'] = 0,
		f[S[i] - 'a']++;
	vpii v;
	rep(i, 0, n - 1){
		f[S[i] - 'a']--;
		if(done[S[i] - 'a'] == 1)
			continue;
		done[S[i] - 'a'] = 1;
		while(v.empty() == 0){
			if(f[v.back().S] == 0)
				break;
			if(v.back().S > S[i] - 'a')
				break;
			done[v.back().S] = 0;
			v.pop_back();
		}
		v.pb(i, S[i] - 'a');
	}
	sort(all(v));
	for(auto &i: v)
		cout << (char)(i.S + 'a'), f[i.S] = 0;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}