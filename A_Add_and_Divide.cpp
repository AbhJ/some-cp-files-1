#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
map<pair<int, int>, int>dp;
// int f(int a, int b){
// 	if(dp.count(pair<int, int>{a, b}))return dp[pair<int, int>{a, b}];
// 	if(a == 0)return a;
// 	if(b == 1 or f(a / 2, b) == 1)return dp[pair<int, int>{a, b}] = 1 + f(a, b + 1);
// 	return dp[pair<int, int>{a, b}] = 1 + min(f(a / 2, b), f(a, b + 1));
// }
int f(int a, int b){
	if(b == 1)return inf;
	if(a == 0)return 1;
	return 1 + f(a / b, b);
}
int32_t main()
{
  ibs;cti;
  int t;cin>>t;while(t--){
	  int a, b;
	  int ans = 1e9;
	  cin >> a >> b;
	  rep(i, 1, a - b + 1){
		b += i;
		ans = min(ans, i + f(a, b));
		b -= i;
	  }
	  cout << min(ans, f(a, b));
	  cout << "\n";
  }
  return 0;
}