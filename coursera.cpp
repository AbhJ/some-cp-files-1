#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int count=0;
    string s;
    cin>>s;
    int l=s.length();
    if(s.back()=='9')
        cout<<s.length()+1<<endl;
    else cout<<s.length();
    return 0;
}
