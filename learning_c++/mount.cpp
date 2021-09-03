#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0,i=0,j=0;
	int q=0;
	cin>>n;
	cin>>q;
	unsigned long long left=0,right=0,query=0;
	unsigned long long a[20000000],d[10000000];

	for(i=0;i<2*n;i+=2){
		scanf("%lld",&left);
		scanf("%lld",&right);
		a[i]=left;
		a[i+1]=right;
		d[(i/2)]=right-left+1;
	}
	// for(i=0;i<2*n;i++){
	// 	cout<<a[i]<<endl;
	// }
	// for(i=0;i<n;i++){
	// 	cout<<d[i]<<endl;
	// }
	while(q--){
		scanf("%lld",&query);
		unsigned long sum=0;
		for(j=0;query>sum;j+=1){
			sum+=d[j];
		}
		// cout<<sum<<endl;
		cout<<(query-sum+a[(2*(j-1)+1)])<<endl;
	}



	return 0;
}