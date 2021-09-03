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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N];multiset<int>s;
void solve(){
	cin >> n;
	fill(a, a + 1 + n, 0);
	int ok = 1;
	rep(i, 1, n){
		cin >> a[i];
		s.insert(a[i]);
	}
	rep(i, 1, n)if(s.count(i) == 0)ok = 0;
	cout << ok;
	int last = 1, l = 1, r = n;
	rep(i, 1, n - 1){
		if(s.count(i) == 1);
		else break;
		if(a[l] == i)l++;
		else if(a[r] == i)r--;
		else break;
		last = i + 1;
	}
	// if(last == n)last = n + 1;
	if(s.count(last));
	else last--;
	int cnt = 1;
	rep(i, 1, n - last -1)cout << 0, cnt++;
	s.clear();
	rep(i, 1, n - 1 - (n - last - 1)){
		cnt++;if(cnt == n + 1)break;cout << 1;
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}