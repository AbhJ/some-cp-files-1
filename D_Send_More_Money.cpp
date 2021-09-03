//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 23 in 05 : 18 : 46
//title - D_Send_More_Money.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
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
string s[3];int a[3];
void solve(){
	rep(i, 0, 2)
		cin >> s[i];
	map<char, int>m;
	rep(j, 0, 2)
		for(auto &i: s[j])
			if(m.count(i) == 0)
				m[i] = m.size();
	if(m.size() > 10){
		cout << "UNSOLVABLE";
		return;
	}
	vi A(10);
	iota(all(A), 0);
	do{
		int F = 1;
		rep(j, 0, 2){
			a[j] = 0;
			if(A[m[s[j][0]]] == 0)
				F = 0;
			for(auto &k: s[j])
				a[j] = 10 * a[j] + A[m[k]];
		}
		if(F == 1 and a[0] + a[1] == a[2]){
			rep(j, 0, 2)
				cout << a[j] << "\n";
			return;
		}
	}while(next_permutation(all(A)));
	cout << "UNSOLVABLE";
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