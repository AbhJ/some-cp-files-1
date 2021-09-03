//Coded by Abhijay Mitra
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
#define pb push_back
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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n;string s, tmp;
set<pii >S;
//may go into corrupt

//if answered by atleast two corrupt it is corrupt
//otherwise peace

vvi v;

int a[N];
//corrupt

bool cmp(pair<vector<int>, int > a, pair<vector<int>, int > b){
	if(a.F == b.F)return a.S < b.S;
	return a.F < b.F;
}

void solve(){
//   cin >> n;
//   cout.flush();
//   fflush(stdout);
  vi vec;
  getline( std::cin, s);
  getline( std::cin, s);
//   cout << s << "\n" ;
  rep( i, 0, s.length() - 1){
    if(s[i] == ','){vec.pb(stoll(tmp));tmp.clear();v.pb(vec), vec.clear();continue;}
	if(s[i] == ' '){vec.pb(stoll(tmp));tmp.clear();continue;}
    tmp.pb(s[i]);
  }
  vec.pb(stoll(tmp));tmp.clear();v.pb(vec), vec.clear();
//   for(auto i: v){
// 	  for(auto j: i)cout << j << " ";
// 	  cout << "\n";
//   }
  vector<pair<vector<int>, int > > z;
  for(auto V: v){
	  int m = V.size();
	  vi Z;
	  rep( i, 1, m - 1){
		  Z.pb(i);
		  pii p = pii{ min( V[0], V[i]), max( V[0], V[i])};
		  if(S.count(p) == 1){
			  S.erase(p);
			  a[V[0]] = 1;
			  a[V[i]] = 1;
			  continue;
		  }
		  S.insert(p);
	  }
	  sort(all(Z));
	  z.pb(mp(Z, V[0]));
  }
  sort(all(z), cmp);
  for(auto Z: z){
	  int m = Z.F.size();
	  int ele = Z.S;
	  vi V = Z.F;
	  int cnt = 0;
	  rep( i, 0, m - 1){
		  if(a[V[i]] == 1)cnt++;
	  }
	  if(cnt > 1){
		  a[ele] = 1;
	  }
  }
  int zz = 0;
  rep( i, 0, N - 1){
	  if(a[i] == 1 and zz == 1){cout << "," << i;continue;}
	  if(a[i] == 1 and zz == 0){zz = 1;cout << i;}
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