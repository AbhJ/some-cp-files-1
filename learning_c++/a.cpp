#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	int m=0;
	int k=0;
	cin>>n;
	cin>>m;
	cin>>k;
	int i=0;
	int j=0;
	int a[m][n];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cin>>a[m][n];
	}
	int i1=0,j1=0,count=0;
	for(i=0;i<n-k;i++){
		for(j=0;j<m-k;j++)
			for(i1=i;i1<i+k;i++){
				for(j1=j;j1<j+k;j++){
					if(a[i1][j1]==0)
						a[i1][j1]=1;
					else a[i1][j1]=0;
				}
			}
	}
	

return 0;
}