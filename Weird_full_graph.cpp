//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 30 in 20 : 22 : 07
//title - Weird_full_graph.cpp
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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N][N], m, x, y, c;
void d(int s, vector<int> & D, vector<int> & p) {
    D.assign(n + 1, inf);
	// rep(i, 1, n)
	// 	D[i] = a[i][i];
    p.assign(n + 1, -1);
    vector<bool> u(n + 1, false);

    D[s] = 0;
   	rep(i, 1, n){
        int v = -1;
        rep(j, 1, n){
            if (!u[j] && (v == -1 || D[j] < D[v]))
                v = j;
        }

        if (D[v] == inf)
            break;

        u[v] = true;
        rep(j, 1, n) if(j != v) {
            int to = j;
            int len = a[i][j];

            if (D[v] + len < D[to]) {
                D[to] = D[v] + len;
                p[to] = v;
            }
        }
    }
}
void solve(){
	cin >> n;
	rep(i, 1, n){
		cin >> c;
		rep(j, 1, n)
			a[i][j] = c;
	}
	cin >> m;
	rep(i, 1, m)
		cin >> x >> y >> c,
		a[x][y] = c;
	vi V;
	rep(i, 1, n){
		vi D, p;
		d(i, D, p);
		rep(j, 1, n)
			if(j != i)
				V.pb(D[j]);
			else
				V.pb(a[i][i]);
	}
	int mi = *min_element(all(V));
	// cout << mi;
	cout << (count(all(V), mi) * mi);
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}