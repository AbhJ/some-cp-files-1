//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 15 in 07 : 13 : 30
//title - G_Strange_Beauty.cpp
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
vvi prime_vector_sieve(){
  vvi prime(N);
  for(int i = 2;i < N; ++i)if(prime[i].empty())
        for(int j = i; j < N; j += i){
            prime[j].push_back(i);
        }
  return prime;
}
int n, A[N], sp[N];vvi a;vi B[N];
int parent[N],ind[N];set<int>s;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = 0;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
        if (ind[a] == ind[b])
            ind[a]++;
    }
}
int cnt[N], dp[N];
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> A[i],
		cnt[A[i]]++;
	// rep(i, 1, n)
	// 	make_set(i);
	// rep(i, 1, n)
	// 	for(auto &j: a[A[i]])
	// 		B[j].pb(i);
	// rep(i, 1, 3){
	// 	for(auto &j: B[i])
	// 		cout << j;
	// 	cout << "\n";
	// }
	// rep(i, 1, N - 1)
	// 	if((int)B[i].size() > 2)
	// 		rep(j, 1, (int)B[i].size() - 1)
	// 			union_sets(B[i][j], B[i][j - 1]);
	// rep(i, 1, n)
	// 	s.insert(find_set(i));
	// cout << (int)s.size();
	rep(i, 1, N - 1){
		dp[i] += cnt[i];
		// if(dp[i] == 0)
		// {
			for(int j=2*i;j<N;j+=i)
			{
				dp[j] = max(dp[i], dp[j]);
			}
		// }
	}
	rep(i, 1, n)
		cnt[A[i]] = 0;
	vi v;
	rep(i, 1, n)
		v.pb(dp[A[i]]);
	// for(auto &i: v)
	// 	cout << i << " ";
	cout << n - *max_element(all(v)) << " ";
	fill(dp + 1, dp + N, 0);
	// s.clear();
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
//   a = prime_vector_sieve();
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}