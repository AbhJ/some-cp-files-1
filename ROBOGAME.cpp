#include <bits/stdc++.h>
#define ll long long int
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
int A[N+1], B[N+1];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int right=INT_MIN,left;
        bool flag1=false;
        for (int i = 0; i < s.length(); ++i)
        {
            if ((right>=i-s.at(i)+'0')&&s.at(i)!='.')
            {
                cout<<"unsafe"<<"\n";
                flag1=true;
                break;
            }
            if (s.at(i)!='.')
            {
                right=i+s.at(i)-'0';
            }
        }
        if (flag1)
            continue;
        else cout<<"safe"<<"\n";
    }
    return 0;
}