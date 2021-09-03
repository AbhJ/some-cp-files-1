//ulrich_nielsen on Codeforces
//I'll reveal my identity soon
//target CM
/* __ __  _      ____   ____   __  __ __      ____   ____    ___  _     _____   ___  ____       _____  ____   ___   ___ ___      ______  __ __    ___      ___      ___   ____  ___
  |  |  || |    |    \ |    | /  ]|  |  |    |    \ |    |  /  _]| |   / ___/  /  _]|    \     |     ||    \ /   \ |   |   |    |      ||  |  |  /  _]    |   \    /  _] /    ||   \
  |  |  || |    |  D  ) |  | /  / |  |  |    |  _  | |  |  /  [_ | |  (   \_  /  [_ |  _  |    |   __||  D  )     || _   _ |    |      ||  |  | /  [_     |    \  /  [_ |  o  ||    \
  |  |  || |___ |    /  |  |/  /  |  _  |    |  |  | |  | |    _]| |___\__  ||    _]|  |  |    |  |_  |    /|  O  ||  \_/  |    |_|  |_||  _  ||    _]    |  D  ||    _]|     ||  D  |
  |  :  ||     ||    \  |  /   \_ |  |  |    |  |  | |  | |   [_ |     /  \ ||   [_ |  |  |    |   _] |    \|     ||   |   |      |  |  |  |  ||   [_     |     ||   [_ |  _  ||     |
  |     ||     ||  .  \ |  \     ||  |  |    |  |  | |  | |     ||     \    ||     ||  |  |    |  |   |  .  \     ||   |   |      |  |  |  |  ||     |    |     ||     ||  |  ||     |
   \__,_||_____||__|\_||____\____||__|__|    |__|__||____||_____||_____|\___||_____||__|__|    |__|   |__|\_|\___/ |___|___|      |__|  |__|__||_____|    |_____||_____||__|__||_____|
*/
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define per(i,b,a) for (int i = b; i >= a; i--)
#define pb emplace_back
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
using vi = std::vector<int>;
using vvi = std::vector<vi>;
#define all(x)     x.begin(), x.end()
using pii = std::pair<int,int>;
#define S second
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define F first
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
#define ll int
const int inf = 1e18+10;
// const ll M = 998244353;
// const int M = 1e9+7;
const int N = 5e3;
int n, a[N], b[N], dp[N][N], o[N], ans;
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, n)
		cin >> b[i];
	//reverse from j to i
	rep(i, 1, n)
		o[i] = o[i - 1] + a[i] * b[i];
	rep(i, 1, n){
		int cnt = o[i - 1];
		per(j, i, 1){
			cnt -= a[j] * b[j];
			cnt += a[j] * b[i] + a[i] * b[j];
			ans = max(ans, cnt);
		}
	}
	cout << ans;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
//   cin>>t;
  while(t--){
	  solve();
	  cout<<"\n";
  }
  return 0;
}