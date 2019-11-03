#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 40
void sum(int&p, int n, std::vector<int> d/*;*/)

{

	int i;

	p = 0;

	for(i = 0; i < n; ++i)

	p = p + d[i];

}
int main(){
	ios::sync_with_stdio(false);
	int i;

	int accum = 0;

	// int data[N];
	std::vector<int> data;
	for(i = 0; i < N; ++i)

	// data[i] = i;
		data.push_back(i);

	sum(accum, N, data);

	// printf("sum is %d\n", accum);
	cout<<"sum is "<<accum<<"\n";
	return 0;
	}

// #include <stdio.h>





// int main()

// {


// return 0;

// }