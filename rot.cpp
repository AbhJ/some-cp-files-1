#include<bits/stdc++.h>
using namespace std;

int main(){
	int t=0;
	cin>>t;
	while(t--){
		int n=0,k=0;
		cin>>n;
		cin>>k;
		int i=0;
		int a[n];
		for(i=0;i!=n;i++){
			cin>>a[i];
		}
		int j=0;
		 for (int i = 0; i !=k; i++){
			    int x = a[n - 1]; 
                for (j = n; j > 0; j--) 
                a[j] = a[j - 1];  
                a[0] = x; 
		}
	for(int j=0;j!=n;j++){
			cout<<a[j]<<" ";
		}
	}
return 0;
}