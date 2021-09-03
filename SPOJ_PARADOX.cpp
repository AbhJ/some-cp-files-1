//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 14 in 18 : 08 : 23
//title - Paradox.cpp
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
const int N=3e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N];
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
int get(int i, int t){
	return i + 102 * t;
}
void solve(){
	cin >> n;
	//2 sat problem
	rep(i, 1, n){
		int x;string s;
		cin >> x >> s;
		if(s == "false")
			union_sets(get(i, 0), get(x, 1)),
			union_sets(get(i, 1), get(x, 0));
		else
			union_sets(get(i, 1), get(x, 1)),
			union_sets(get(i, 0), get(x, 0));
	}
	rep(i, 1, n)
		if(find_set(get(i, 0)) == find_set(get(i, 1))){
			cout << "PARADOX";
			rep(i, 1, N - 1)make_set(i);
			return;
		}
	if(n == 0)exit(0);
	cout << "NOT PARADOX";
	rep(i, 1, N - 1)make_set(i);
	return;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  rep(i, 1, N - 1)make_set(i);
  int xx=0;
  while(1){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}