//TC 441-D2-1  Time: 11:35 - 12:20 , Points = 110.29  , 2 wrong test cases

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class DifferentStrings{

public: 

	int diff(string A,string B){
	
		int res = 0;

		for(int i=0; i<B.length(); i++){

				if(A[i]!=B[i])
					res++;
			}

			return res;
	

	}
	int minimize(string A, string B){

		

		if(A.length()==B.length()){

			return diff(A,B);
			
		}

		else
		{
			int pos = B.find(A,0);
			
			if(pos != string::npos){

				A = B.substr(0,pos) + A;

				if(A.length() < B.length()){
				
					A += B.substr(A.length(),B.length());
				}

				return diff(A,B);
			}

			else{

				int val0,val1;
				string copy = A;

				int length = B.length() - A.length();

				A = B.substr(0,length) + A;

				val0 = diff(A,B);

				A = copy;

				A = A + B.substr(A.length(),B.length());

				val1 = diff(A,B);


				return min(val0,val1);

			}
		}

	}


};
int main() {

	/*	SoccerLeagues a;

	string arr[] = {"-WW",
	"W-W",
	"WW-"};

	vector<string> x(arr,arr+sizeof(arr)/sizeof(*arr));
	a.points(x);
	*/	

	string x = "giorgi";
	string y = "igroig";
	
	DifferentStrings a;



	cout<<a.minimize(x,y)<<endl;
	cout<<endl;
	system("pause");
	return 0;
}
