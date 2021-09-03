// Question hacker Earth
// As you all know , We are at war and our brave soldiers are fighting for our country. KillCode 
// is also one of the soldiers and is trying to help our country . To do this he needs a Launcher 
// that is kept a small distance from him. Now , to get the Launcher , He needs to solve the following problem :

// Problem consists of q queries one after the another and Killcode needs to tell the total numbers that can help to make a prime number .

// For example : let say 7 is a prime number , following numbers that can help to make 7 are  :
//  (1,6),(2,5)(3,4)

// **Note **

// Both numbers should be combination of even-odd. And (1,6),(6,1) both are counted as 1. So, ans for 7 is 3.

// Now, for each query , Killcode would be given a number n and he has to tell the sum of all the numbers 
// that can help to make specific prime number from 1 to n(both inclusive).

// Constraints

// 1<=q<=10^5

// 1<=n<=5*10^6

// Input

// first line will contain an integer q , denoting the number of queries, next q lines will contain a number n.

// Output

// Output the answer in each single line.

// Note Answer can be very large , use modulo 10^8+7.

// As the time is very less, Help Killcode to solve this Problem So that he can save the country .
// SAMPLE INPUT 
// 3
// 2
// 8
// 11
// SAMPLE OUTPUT 
// 0
// 6
// 11
// Explanation
// For first testcase :

// There is only 1 prime number less than equal to 2 that is 2 itself and 2 can't be made by combination of odd-even number .

// For Second testcase :

// There are 4 prime numbers less than equal to 8 ,

// for 2 - 0 , for 3 - (1,2) , for 5 - (1,4),(2,3) , for 7 - (1,6),(2,5),(3,4)

// So the total combinations are 6%(10^8+7) = 6

// For Third testcase "

// There are 5 prime numbers less than equal to 11 :

// for 2 - 0 , for 3 - (1,2) , for 5 - (1,4),(2,3) , for 7 - (1,6),(2,5),(3,4) , for 11 - (1,10),(2,9),(3,8),(4,7),(5,6)

// So the total numbers add upto 11%(10^8+7) = 11






#include <bits/stdc++.h>

using namespace std;

void Prime(vector<bool> &prime){
    for(long long int p=2;p*p<=5000001;p++)
    {
    if(prime[p])
    for(long long int i=p*p;i<=5000001;i+=p)
    prime[i]=false;
    }
}
void Compute(vector<bool> prime,vector<long long unsigned int> &pairs){
    pairs[0]=0;
    pairs[1]=0;
    pairs[2]=0;
    for(long long unsigned int i=3;i<=5000001;i++){
        if(prime[i])
        pairs[i] =((pairs[(i-1)])+((i)/2))%100000007;
        else
        pairs[i]=pairs[(i-1)]%100000007;
    }

}
int main() {
int q;
scanf("%d",&q);
vector<bool> prime(5000001,true);
prime[0]=prime[1]=false;
vector<long long unsigned int> pairs(5000001,0);
Prime(prime);
Compute(prime,pairs);
while(q>0)
{
long long unsigned int num;
scanf("%llu",&num);
if(num<=2)
printf("0\n");
else
{

printf("%llu\n",pairs[num%100000007]);
}

q--;
}
}