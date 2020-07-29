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
#define pb push_back
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
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
void solve(){
  int n,m;cin>>n>>m;
  if(n==2){
    cout<<0<<"\n";
    rep(i,1,m){
      cout<<1<<" "<<i<<"\n";
    }
    per(i,m,1){
      cout<<2<<" "<<i<<"\n";
    }
    cout<<1<<" "<<1<<"\n";
    return;
  }
  if(m==2){
    cout<<0<<"\n";
    rep(i,1,n){
      cout<<i<<" "<<1<<"\n";
    }
    per(i,n,1){
      cout<<i<<" "<<2<<"\n";
    }
    cout<<1<<" "<<1<<"\n";
    return;
  }
  if(((n&1)^(m&1) and n!=1 and m!=1) or ((n&1)==0) and (m&1)==0){
    cout<<0<<"\n";
    cout<<1<<" "<<1<<"\n";
    if(n&1){
      int x=0;
      rep(j,2,m){
        if(x==0){
          rep(i,1,n-1){
            cout<<i<<" "<<j<<"\n";
          }
        }
        else{
          per(i,n-1,1){
            cout<<i<<" "<<j<<"\n";
          }
        }
        x^=1;
      }
      per(j,m,1){
        cout<<n<<" "<<j<<"\n";
      }
      per(i,n-1,1){
        cout<<i<<" "<<1<<"\n";
      }
    }
    else{
      int x=0;
      rep(i,2,n){
        if(x==0){
          rep(j,1,m-1){
            cout<<i<<" "<<j<<"\n";
          }
        }
        else{
          per(j,m-1,1){
            cout<<i<<" "<<j<<"\n";
          }
        }
        x^=1;
      }
      per(i,n,1){
        cout<<i<<" "<<m<<"\n";
      }
      per(j,m-1,1){
        cout<<1<<" "<<j<<"\n";
      }
    }
    return;
  }
  cout<<1<<"\n";
  if(m&1){
    cout<<n<<" "<<m<<" "<<1<<" "<<1<<"\n";
  }
  else cout<<1<<" "<<m<<" "<<1<<" "<<1<<"\n";
  int x=0;
  rep(j,1,m){
    if(x==0){
      rep(i,1,n){
        cout<<i<<" "<<j<<"\n";
      }
    }
    else{
      per(i,n,1){
        cout<<i<<" "<<j<<"\n";
      }
    }
    x^=1;
  }
  cout<<1<<" "<<1;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}