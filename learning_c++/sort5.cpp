#include<bits/stdc++.h>
using namespace std;
int main(){
	int h[100000];
	int t;
	cin>>t;
	while(t--){
		int N=0,i=0,j=0;
		cin>>N;
		int a[N];
		for(i=0;i<N;i++){
			cin>>a[i];
		}
		sort(a,a+N);
		// for(i=0;i<N;i++){
		// 	cout<<a[i]<<endl;
		// }
		int noofheights=0;
		for(i=0;i<N;i++){
			if((i==0)||a[i]!=a[i-1])
				noofheights++;
		}
		// cout<<noofheights<<endl;
		int count=0;int flag=0;
		//getting the frequency distribution
		for(i=0;i<noofheights;i++){
			for(;((flag==0)||(a[j]==a[j-1]))&&(j<N);j++){
					count++;flag=1;
			}
			h[i]=count;
			count=0;
			flag=0;
		}
		// for(i=0;i<noofheights;i++){
		// 	cout<<h[i]<<endl;
		// }
		int max=0;
		int min=0;
		for(i=0;i<noofheights;i++){
			if(i==0||h[i]>max)
				max=h[i];
		}
		for(i=0;i<noofheights;i++){
			if(i==0||h[i]<min)
				min=h[i];
		}
		if(max==min)
			cout<<"-1"<<endl;
		else
		
	cout<<(max-min)<<endl;


	}
return 0;
}