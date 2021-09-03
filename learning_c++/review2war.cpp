// Everyone is now in search for power! Some people think that some numbers have large powers so they use them a lot. After some search, Omar tried on many numbers to explore their powers, so now he know the numbers with infinite power!

// The numbers with infinite powers are really easy to find, they are numbers which have all their digits as even numbers, so  has infinite power but  doesn't have infinite power.

// But now there are only small amount of infinite power numbers. So Omar starts again searching about numbers with large (but not infinite) powers. He found out that power of a number (N) is equal to division of absolute difference between N and the number with infinite number not less than N over absolute difference between N and the number with infinite number not greater than N.

// So given a number, help Omar finding power of the number.

// Input Format:
// First line of the input is an integer (T), number of test cases.
// For each test case an integer N is given in new line.

// Output Format: 
// If the number has infinite power, output "Unlimited Power" (without quotes) in a separate line, otherwise output the required ratio (in the most simplified form) in a separate line.

// Constraints:

// Note: Large I/O files. Use faster input, output methods.

// SAMPLE INPUT 
// 2
// 11
// 22
// SAMPLE OUTPUT 
// 3/1
// Unlimited Power
// Explanation
// Case #1:


// Time Limit: 1.0 sec(s) for each input file.
// Memory Limit: 256 MB
// Source Limit: 1024 KB
#include <bits/stdc++.h>
using namespace std;

// #include <boost/rational.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
#define watch(x) cout << (#x) << " is " << (x) << endl
int isUnlimited(long long int num){
    while(!(num%2)&&(num!=0))
	        num/=10;
	       // watch(num);
        if(!num){
            return 1;
        }
        else return 0;
}
// long long int gcd(long long int a,long long int b)
// {
//   if(b==0)
//   return a;
//   else
//   return gcd(b,a%b);
// }
// void DoubleToRational(long double a)
// {
//   long long int t=1;
//   while((long double)t*a!=(long long int)(t*a))
//   {
//   //cout<<t*a<<" "<<(float)t*a<<" "<<(int)(t*a)<<endl; // For Checking
//   t=t*10;
//   }
//   long long int k=gcd((long long int)t*a,t);
//   cout<<(long int)t*a/k<<"/"<<t/k<<"\n";
// }

 void simplify_fraction(long long int num,long long int denom)
            {
             for (long long int i = denom; i>=2; i--)
             {
              if (num % i == 0 && denom % i == 0)
              {
              num = num/i;
              denom = denom/i;
              }
             }
            //  cout << "Fraction: ";
            //  if (denom == 1)
            //   cout << num;
            //  else
              cout << num << "/" << denom;
             cout << endl;
            }
int main(){
	ios::sync_with_stdio(false);
	typedef long long ll;
	int t;
	cin>>t;
	long long int n,num,i=0,up,down=0,dec=0;
	while(t--){
	    cin>>n;
	    up=n;
	    down=n;
	    num=n;
	    if(isUnlimited(n)){
	        cout<<"Unlimited Power\n";
	        continue;
	    }
	        
        while(1){
            up++;
            if(!isUnlimited(up))
	            continue;
	        break;
        }
        while(1){
            down--;
            if(!isUnlimited(down))
	            continue;
	        break;
        }
        // watch(up);
        // watch(down);
        long double number=0.0,down1=down;
        
        number=(long double)(up-n)/(n-down1);
        if(number<0)
            number=-1*number;
            
        // watch(number);
        if(number==floor(number)){
            cout<<number<<"/1\n";
            continue;
        }
        //  DoubleToRational(number);
        simplify_fraction(11,3);
        
        
         long double fractional_part = number - floor(number);

            for (long double i = .1, j = 10;  ; i/=10, j*=10)
                {
              if ( fractional_part >= i )
              {
              simplify_fraction(number * j, j);
              break;
              }
             }
           
             
            
        
        // else{
        //     while(i)
        // }
            
	}
	return 0;
}




            
           
        
	    