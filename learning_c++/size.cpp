#include <iostream>
#include <cmath>
using namespace std;
int main(){
	cout <<"The size of int is = "<<sizeof(int)<<endl;
	cout <<"The size of float is = "<<sizeof(float)<<endl;
	cout <<"The size of char is = "<<sizeof(char)<<endl;
	cout <<"The size of unsigned int is = "<<sizeof(unsigned int)<<endl;
	cout <<"The size of short int is = "<<sizeof(short int)<<endl;
	cout <<"The size of long int is = "<<sizeof(long int)<<endl;
	cout <<"The size of double is = "<<sizeof(double)<<endl;
	cout <<"The size of float is = "<<sizeof(float)<<endl;
	// enum month{Jan, Feb, Mar, Apr, May, Jun, Jul , Aug, Sep, Oct, Nov, Dec};
	// int count=0;
	// enum month i=Jan;
	// for(i=Jan;count<5;i=(i+1)%12{
	// 	cout<<i<<endl;
	// 	if(i==Dec)
	// 		count++;
	// }
	cout<<"Enter a\t";
	int a=0,b=0;
	cin>>a;
	cout<<"Enter b\t";
	cin>>b;
	cout<<"\nThe values that you have entered are "<<a<<" and "<<b;
	cout<<"\nI am a Chor\tB\nHello Chor\tB";

	int marks, sum = 0, min=0, max=0, numStudents;
	float average; // Variable declarations
	cout << "\nGive number of students: "; cin >> numStudents;
	int count=0; // Count of student marks processed
	while (count!= numStudents) {
		cout << "\nGive marks of student " << ++count<< " :\t";
		cin >> marks;
		sum+=marks;
		// Update sum, max, min
		if(marks>max)
			max=marks;
		if(count==1||marks<min)
			min=marks;
	}
	average = (float)sum/count;
	cout<<"\nTherefore the average is:\t"<<average;
	cout<<"\nAnd the maximum is:\t"<<max;
	cout<<"\nThe minimum is:\t"<<min;
	// Print average, sum, min, max
	return 0;
} 