#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[n][n];
		int i=0,j=0;
		for(i=0;i!=n;i++){
			for(j=0;j!=n;j++){
				cin>>m[i][j];
			}
		}
		int sum=0,p=0,q=0;
		for(i=0;i!=n;i++){
			for(p=i;p!=n;p++){
				for(j=0;j!=n;j++){
					for(q=j;q!=n;q++){
						if(m[i][j]>m[p][q])
							sum++;
					}
				}
				
			}
		}
	cout<<sum<<endl;
	}
return 0;
}