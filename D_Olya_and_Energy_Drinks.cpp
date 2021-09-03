//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 11 in 20 : 07 : 07
//title - D_Olya_and_Energy_Drinks.cpp
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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
char a[N][N];int n, m, k, vis[N][N], sx, sy, tx, ty;queue<pii>q;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void solve(){
	cin >> n >> m >> k;
	rep(i, 1, n)
		rep(j, 1, m){
			cin >> a[i][j];
			if(a[i][j] == '#')vis[i][j] = - inf;
			else vis[i][j] = inf;
		}
	cin >> sx >> sy >> tx >> ty;
	q.push(pii {sx, sy});
	vis[sx][sy] = 0;
	int taka = 0;
	while(q.empty() == 0){
		int z = (int)q.size();
		while(z-- != 0){
			int x = (q.front()).F, y = (q.front().S);
			q.pop();
			if(vis[x][y] == -inf)continue;
			if(pii {x, y} == pii {tx, ty}){
				cout << taka;
				return;
			}
			rep(d, 0, 3){
				rep(i, 1, k){
					int X = x + dx[d] * i;
					int Y = y + dy[d] * i;
					if(X < 1 or X > n or Y < 1 or Y > m or vis[X][Y] == - inf)break;
					if(vis[X][Y] <= vis[x][y])break;
					if(vis[X][Y] <= 1 + vis[x][y])continue;
					vis[X][Y] = 1 + vis[x][y];
					q.push(pii {X, Y});
				}
			}
		}
		taka++;
	}
	cout << - 1;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}