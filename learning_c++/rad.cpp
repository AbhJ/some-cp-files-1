#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	//number of points lying on the plane
	int i=0;
	int x=0;
	int y=0;
	unsigned long long r[n];
	for(i=0;i<n;i++){
		cin>>x;
		cin>>y;
		r[i]=(x*x+y*y);
	}
	int q=0;
	int ans=0;
	int query=0;
	//number of queries
	cin>>q;
	while(q--){
		ans=0;
		cin>>query;
		for(i=0;i<n;i++){
			if(query*query>=r[i])
			ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}