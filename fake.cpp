#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
int w, h, n;
int32_t main()
{
  ibs;cti;
  int t;cin>>t;while(t--){
    cin >> w >> h >> n;
    int cnt1 = 1, cnt2 = 1;
    while(h & 1 ^ 1)cnt1++, h >>= 1;
    while(w & 1 ^ 1)cnt2++, w >>= 1;
    if(cnt1 == 1 and h == 1)
      cout << (cnt2 + 1 >= n ? "YES" : "NO");
    else if(cnt2 == 1 and w == 1)
      cout << (cnt1 + 1 >= n ? "YES" : "NO");
    else
      cout << (cnt1 * cnt2 >= n ? "YES" : "NO");
    cout << "\n";
  }
  return 0;
}