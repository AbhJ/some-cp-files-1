#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main(){
	float x1=0,x2=0,x3=0,x4=0;
	float y1=0,y2=0,y3=0,y4=0;
	cin>>x1;cin>>y1;
	cin>>x2;cin>>y2;
	cin>>x3;cin>>y3;
	cin>>x4;cin>>y4;
	float val = PI / 180.0;
	//cout<<val<<endl;
	float xc=0,yc=0;
	xc=(x1+x2+x3+x4)/4;
	yc=(y1+y2+y3+y4)/4;
	float t=0;
	float v=0;
	float x1n=1,x2n=1,x3n=1,x4n=1;
	float y1n=0,y2n=0,y3n=0,y4n=0;
	float omega=0;
	cin>>v;
	cin>>omega;
	for(t=0;((x1n>0)&&(x2n>0))&&((x3n>0)&&(x4n>0));t+=0.000001){
		x1n=(x1-xc)*cos(omega*t*val)-(y1-yc)*sin(omega*t*val)+xc-v*t;
		x2n=(x2-xc)*cos(omega*t*val)-(y2-yc)*sin(omega*t*val)+xc-v*t;
		x3n=(x3-xc)*cos(omega*t*val)-(y3-yc)*sin(omega*t*val)+xc-v*t;
		x4n=(x4-xc)*cos(omega*t*val)-(y4-yc)*sin(omega*t*val)+xc-v*t;
	}
	cout<<t;
return 0;
}