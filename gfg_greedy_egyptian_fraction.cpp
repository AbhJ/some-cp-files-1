#include <bits/stdc++.h>
#define ll unsigned long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
// ll A[10000];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
void solve(int n, int d){
    if(d==0||n==0)
        return;
    if(n%d==0){
        cout<<n/d;//input is actually integer
        return;
    }
    if(d%n==0){
        cout<<"1/"<<d/n;
        return;
    }
    if(n>d){
        cout<<n/d<<" + ";
        solve(n%d,d);//mixed fractions
        return;
    }










    int x=d/n+1;
    cout<<"1/"<<x<<" + ";
    solve(n*x-d,d*x);
}
int main(){
    ibs;cti;
    int n,d;
    cin>>n>>d;
    solve(n,d);
    return 0;
}