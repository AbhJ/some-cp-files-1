#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
int32_t main()
{
  ibs;cti;
  int t;cin>>t;while(t--){
	  int n, k;
	  cin >> n >> k;
	  vector<int>v(max(n, k) + 1);
	  v[0] = - 1;
	  per(i, n, 1){
		  if(k < i or v[k - i] == 0)
		  	v[i] = 1;
	  }
	  cout << accumulate(v.rbegin(), prev(v.rend()), 0) << "\n";
	  rep(i, 1, n){
		  if(v[i] == 1)
		  	cout << i << " ";
	  }
	  cout << "\n";
  }
  return 0;
}