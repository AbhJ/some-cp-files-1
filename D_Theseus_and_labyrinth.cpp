//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 01 in 00 : 43 : 23
//title - D_Theseus_and_labyrinth.cpp
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
// #define int long long int
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
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, xs, ys, zs, xe, ye;char a[N][N];int d[N][N][4], dp[N][N][4];
map<char, vector<char>> ma;map<char, vpii>w;
int dx[4]={-1,0,1, 0},dy[4]={0 ,1,0,-1};
void solve(){
	cin >> n >> m;
	rep(i, 1, n)rep(j, 1, m){
		cin >> a[i][j];
	}
	rep(i, 1, n)rep(j, 1, m){
		if(a[i][j]=='+')rep(k, 0, 3)d[i][j][k]=1;
		if(a[i][j]=='-')d[i][j][1]=d[i][j][3]=1;
		if(a[i][j]=='|')d[i][j][0]=d[i][j][2]=1;
		if(a[i][j]=='^')d[i][j][0]=1;
		if(a[i][j]=='>')d[i][j][1]=1;
		if(a[i][j]=='v')d[i][j][2]=1;
		if(a[i][j]=='<')d[i][j][3]=1;
		if(a[i][j]=='L')d[i][j][0]=d[i][j][1]=d[i][j][2]=1;
		if(a[i][j]=='R')d[i][j][0]=d[i][j][2]=d[i][j][3]=1;
		if(a[i][j]=='U')d[i][j][1]=d[i][j][2]=d[i][j][3]=1;
		if(a[i][j]=='D')d[i][j][0]=d[i][j][1]=d[i][j][3]=1;
	}
	rep(i, 1, n)rep(j, 1, m)rep(k, 0, 3)dp[i][j][k] = - 1;
	cin >> xs >> ys;
	queue<vi>q;
	q.push(vi{xs, ys, 0});
	cin >> xe >> ye;
	/*
	  0
	3   1
	  2
	*/
	int F = 0;
	dp[xs][ys][0] = 0;
	while(q.empty() == 0){
		int x = (q.front())[0], y = (q.front())[1], z = (q.front())[2];
		q.pop();
		if(x == xe and y == ye){F = z; break;}
		if(dp[x][y][(z + 1) % 4] == - 1)
			dp[x][y][(z + 1) % 4] = dp[x][y][z] + 1,
			q.push(vi{x, y, (z + 1) % 4});
		//z is current level
		//k is door i want to try (0, 1, 2, 3)
		//door k located now that door (z - k + 4) % 4
		rep(k, 0, 3){
			if(x + dx[k] <= n and y + dy[k] <= m and x + dx[k] >= 1 and
			y + dy[k] >= 1 and
			d[x][y][(k - z + 4) % 4] == 1
			and
			d[x + dx[k]][y + dy[k]][((k - z + 6)) % 4] == 1 and dp[x + dx[k]][y + dy[k]][z] == - 1){
				dp[x + dx[k]][y + dy[k]][z] = dp[x][y][z] + 1;
				q.push({x + dx[k], y + dy[k], z});
			}
		}
	}
	cout << dp[xe][ye][F];
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}