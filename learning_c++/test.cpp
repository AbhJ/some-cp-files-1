#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[]={1,99,3,4,5,6,2};
	sort(a,a+7);
	int x= binary_search(a, a + 7, 2);
	cout<<x<<endl;
	return 0;
}