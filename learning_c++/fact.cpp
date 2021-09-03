#include <cmath>
#include<iostream>
using namespace std;
long long int fact(int x){
	if(x==0)
		return 1;
	return (fact(x-1)*x);
}
long long int fibo(int x){
	if(x==1||x==2)
		return 1;
	return (fibo(x-1)+fibo(x-2));
}
int main(){
	int num;
	cout<<"\nEnter a number:\t";
	cin>>num;
	cout<<"The factorial of "<<num<<" is\t"<<fact(num)<<endl;
	cout<<"\nThe "<<num<<"th Fibonacci is\t"<<fibo(num)<<endl;
	return 0;
}