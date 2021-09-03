#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
// C++ program to generate pythagorean
// triplets smaller than a given limit

// Function to generate pythagorean
// triplets smaller than limit
int a, b, c = 0;
int ok(vector<int> x){
	return x[0] * x[0] == x[1] + x[2];
}
vector<int>v;
int f(){
	vector<int> d{a, b, c};
	do{
		if(ok(d))return 1;
	}
	while(next_permutation(d.begin(), d.end()));
	return 0;
}
void pythagoreanTriplets(int limit)
{

	// triplet: a^2 + b^2 = c^2

	// loop from 2 to max_limitit
	int m = 2;

	// Limiting c would limit
	//  ,.begin(), d.end()b and c
	while (c < limit) {

		// now loop on j from 1 to i-1
		for (int n = 1; n < m; ++n) {

			// Evaluate and print triplets using
			// the relation between a, b and c
			a = m * m - n * n;
			b = 2 * m * n;
			c = m * m + n * n;

			if (c > limit)
				break;

			if(f())v.push_back(c);
		}
		m++;
	}
}
int32_t main()
{
  ibs;cti;
  int limit = 1e6;
  pythagoreanTriplets(limit);
  int t;cin>>t;while(t--){
	  int n;cin >> n;
	  cout << (upper_bound(v.begin(), v.end(), n) - v.begin());
	  cout << "\n";
  }
  return 0;
}