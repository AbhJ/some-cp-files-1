#include <bits/stdc++.h>
using namespace std;
int main(){
	int N=0;
	cin>>N;
	int K=0;
	cin>>K;
	int a[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	int temp=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N-1-i;++j){
			if (a[j]%K > a[j+1]%K){
	        	temp=a[j];
	        	a[j]= a[j+1];
				a[j+1]=temp;; 
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
return 0;
}