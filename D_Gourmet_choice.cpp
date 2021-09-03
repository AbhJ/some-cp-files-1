//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 10 in 08 : 26 : 31
//title - D_Gourmet_choice.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, m, A[2 * N], B[N], va[2 * N], ou[2 * N];char c[N][N];
int parent[2 * N],ind[2 * N], in[2 * N];
vi a[2 * N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
queue<int>que;vi ans;
bool topsort()
{
    while(!que.empty())
        que.pop();
    for(int i=1;i<=n + m;i++)
    {
        if(!in[i])
            que.push(i);
    }
    int now,num=0;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
		ans.pb(now);
        num++;
        for(int i=0;i<a[now].size();i++)
        {
            if(--in[a[now][i]]==0)
                que.push(a[now][i]);
        }
    }
	rep(i, 0, (int)ans.size() - 1){
		A[ans[i]] = max(A[ans[i]], 1LL);
		for(auto &j: a[ans[i]])
			A[j] = max(A[j], A[ans[i]] + 1);
	}
	rep(i, 1, n)
		rep(j, 1, m){
			if(c[i][j] == '>' and A[find_set(i)] <= A[find_set(n + j)]){
				cout << "No";
				return 0;
			}
			if(c[i][j] == '<' and A[find_set(i)] >= A[find_set(n + j)]){
				cout << "No";
				return 0;
			}
			if(c[i][j] == '=' and A[find_set(i)] != A[find_set(n + j)]){
				cout << "No";
				return 0;
			}
	}
	return true;
}
queue<int>q;
set<int>s;
void solve(){
	cin >> n >> m;
	rep(i, 1, n)
		rep(j, 1, m)
			cin >> c[i][j];
	rep(i, 1, n + m)
		make_set(i);
	rep(j, 1, m)
		make_set(n + j);
	rep(i, 1, n)
		rep(j, 1, m)
			if(c[i][j] == '=')
				union_sets(i, n + j);
	rep(i, 1, n)
		rep(j, 1, m){
			if(c[i][j] == '<'){
				if(find_set(i) == find_set(n + j)){
					cout << "No";
					return;
				}
				a[find_set(i)].pb(find_set(n + j)),
				in[find_set(n + j)]++;
			}
			if(c[i][j] == '>'){
				if(find_set(i) == find_set(n + j)){
					cout << "No";
					return;
				}
				a[find_set(n + j)].pb(find_set(i)),
				in[find_set(i)]++;
			}
		}
	if(topsort() == 0){
		return;
	}
	cout << "Yes\n";
	rep(i, 1, n)
		cout << A[find_set(i)] << " ";
	cout << "\n";
	rep(j, n + 1, n + m)
		cout << A[find_set(j)] << " ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}