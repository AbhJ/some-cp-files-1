//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 21 in 00 : 52 : 47
//title - D_Binary_Literature.cpp
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
string a, b, c, d, tmp, s, t;int n, ans, z, mi, ma, l, r;
char gg(string s){
	int cn = 0, ct = 0;
	rep(i, 0, 2 * n - 1)
		cn += (s[i] == '0'),
		ct += (s[i] == '1');
	if(cn >= n)
		return '0';
	assert(ct > n);
	return '1';
}
int g(string t, string s){
	if(gg(s) != gg(t))
		return 0;
	char m = gg(s);
	if((int)tmp.empty() == (int)0)
		tmp.clear();
	while(l != t.length() or r != s.length()){
		if(l == t.length())
			tmp += s[r++];
		else if(r == s.length())
			tmp += t[l++];
		else if(s[r] == t[l])
			tmp += t[l++],
			r++;
		else if(s[r] == m)
			tmp += t[l++];
		else
			tmp += s[r++];
	}
	l = r = 0;
	if(tmp.length() <= 3 * n)
		return 1;
	swap(s, t);
	m = gg(s);
	while(l != t.length() or r != s.length()){
		if(l == t.length())
			tmp += s[r++];
		else if(r == s.length())
			tmp += t[l++];
		else if(s[r] == t[l])
			tmp += t[l++], r++;
		else if(s[r] == m)
			tmp += t[l++];
		else
			tmp += s[r++];
	}
	l = r = 0;
	if(tmp.length() <= 3 * n)
		return 1;
	return 0;
}
int f(){
	if(g(a, b))
		return 1;
	if(g(a, c))
		return 1;
	if(g(b, c))
		return 1;
	return 0;
	//no way
}
void solve(){
	cin >> n >> a >> b >> c;
	assert(f());
	cout << tmp << string(3 * n - tmp.length(), '0');
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}