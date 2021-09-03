//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 06 in 17 : 58 : 46
//title - E_Come_Back_Quickly.cpp
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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, a[N * N], b[N * N], c[N * N], dp[N][N];
vvpii A;
vi d, p;
int dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = A.size();
    d.assign(n, inf);
    p.assign(n, -1);
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().S;
        int d_v = q.top().F;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : A[v]) {
            int to = edge.F;
            int len = edge.S;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
	return d[s + (n / 2)];
}
void solve(){
	cin >> n >> m;
	rep(i, 0, 2 * n - 1)rep(j, 0, 2 * n - 1)dp[i][j] = inf;
	rep(i, 0, 2 * n - 1)dp[i][i] = 0;
	A.resize(2 * n);
	rep(i, 0, n - 1)A[i + n].pb(pii{i, 0});
	rep(i, 1, m)
		cin >> a[i] >> b[i] >> c[i],
		dp[a[i] - 1][b[i] + n - 1] = min(c[i], dp[a[i] - 1][b[i] + n - 1]),
		A[a[i] - 1].pb(pii{b[i] - 1 + n, c[i]});
	rep(i, 0, n - 1){
		if(dijkstra(i, p, d) == inf)cout << - 1 << "\n";
		else cout << dijkstra(i, p, d) << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}