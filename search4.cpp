#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,i=0;
	int q=0;
	cin>>n>>q;
	long long int l[n];
	long long int r[n];
	long long int d[n];
	long long int x=0;
	for(i=0;i<n;i++){
		cin>>l[i]>>r[i];
		d[i]=(r[i]-l[i]+1);
	}
	for(i=1;i<n;i++){
		d[i]+=d[i-1];
	}
	while(q--){
		cin>>x;
// 		if(x>d[n]){
// 		    cout<<0<<endl;
// 		    continue;
// 		}
		
		for(i=0;d[i]<x;i++){
		}
		cout<<r[i]-d[i]+x<<endl;
	}
	return 0;
}