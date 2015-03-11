//TC 417-D2-1
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class ReversedSum{

public:

	int rev(int num){
		
		string str;
		stringstream out;
		out<<num;
		str = out.str();
		int length = str.length();
		char temp;
		
		//Reverse
		for(int i=0; i<length/2; i++){		
			temp = str[i];
			str[i] = str[length - i - 1];
			str[length - i - 1] = temp;
		}

	
		return atoi(str.c_str());

	}
	int getReversedSum(int x, int y){

		return rev(rev(x) + rev(y));

	}
};
int main() {

	ReversedSum a;

	cout<<a.getReversedSum(456,789);


	

	return 0;
}
