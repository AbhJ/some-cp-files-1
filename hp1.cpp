#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
	ios::sync_with_stdio(false);
	int n=0,x=0,i=0,temp=0,x1=0,x2=0;
	cin>>n>>x;
	pair<int,int>p(0,0);
	queue<pair<int,int>>mainq,side1q,workq;
	for(i=0;i<n;i++){
		cin>>p.first;
		p.second=i;
		mainq.push(p);
	}
	x1=x;
	int max=-1,pos=-1;
	// for (int i = 0; i < n; ++i)
	// {
	// 	/* code */
	// 	p=side1q.front();
	// 	cout<<p.first<<" "<<p.second<<"\n";
	// 	side1q.pop();
	// }
	while(x1--){
			max=-1;
			pos=-1;
			side1q=mainq;
			while(!mainq.empty())
				mainq.pop();
			for(i=0;i<x;i++){
				p=side1q.front();
				workq.push(p);
				if(p.first>max){
					max=p.first;
					pos=p.second;
				}
				//There may be a problem in the index of the maximum element to be deleted
				side1q.pop();
				if(side1q.empty())
					break;
			}
			while(!side1q.empty()){
				p=side1q.front();
				mainq.push(p);
				side1q.pop();
			}
			while(!workq.empty()){
				p=workq.front();
				
				if((p.first)==max && p.second==pos){
					workq.pop();
				}
				else{
					if(p.first)
						p.first--;
					mainq.push(p);
					workq.pop();	
				}
				
			}
			// side1q=mainq;
			cout<<pos+1<<" ";

	}		
	return 0;
}