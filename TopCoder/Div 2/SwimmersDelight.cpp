//TC 266-D2-1  Points = 249.97

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SwimmersDelight {

public:
	int round(double num){

		int intNum = (int)num;

		if((num-intNum)<0.5)
			return intNum;
		else
			return intNum+1;
	}

	int max3(int num1,int num2,int num3){
		int higher = (num1>num2)? num1 : num2;

		return (higher>num3)? higher : num3;
	}

	int min3(int num1,int num2,int num3){
			int smaller = (num1<num2)? num1 : num2;

			return (smaller<num3)? smaller : num3;
		}

	int longestJump(vector <int> x, vector <int> y) {
		int jump1,jump2,jump3,shortJump,shortJump2,temp;

		//if inputs are not in ascending order
		if(x[1]<x[0]){
			temp = x[0];
			x[0] = x[1];
			x[1]=temp;

			temp = y[0];
			y[0] = y[1];
			y[1] = temp;
		}

		jump1 = x[0];
		jump2 = round(  sqrt ( (double) ( (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]) ) ) );

		jump3 = (10-x[1]);

		//shortJump represents a jump from the first stone to the another shore neglecting the second stone
		shortJump = round( sqrt( (double)( (10-x[0]) * (10-x[0]) ) ) );

		//shortJump2 represents a jump from the first shore to the second stone neglecting the first stone
		shortJump2 = x[1];

		jump2 = min3(shortJump,shortJump2,jump2);

		return max3(jump1,jump2,jump3);
	}

};

int main() {

	SwimmersDelight a;
	vector<int> x(2),y(2);
	x[0] = 2;
	x[1] = 1;
	y[0] = 10;
	y[1] = 1;	//8

	cout << a.longestJump(x,y);

	return 0;
}
