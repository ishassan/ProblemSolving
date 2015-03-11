//TC SRM 393-D2-1
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class VariableSpeedLimit{

public:

	double journeyTime(int journeyLength, vector <int> speedLimit){

		double ret=0;
		for(int i=0; journeyLength>0; i++){

			if(journeyLength>=speedLimit[i]){
			journeyLength-=speedLimit[i];
			ret++;
			if((i+1)==speedLimit.size())
				i=-1;
			}

			else{

				ret += (double) journeyLength / speedLimit[i];

				break;
			}
		}

		return ret;

	}




};

int main(){

	int arr[] = {50,25}
	;
	vector<int> v(arr, arr+sizeof(arr)/sizeof(*arr));


	VariableSpeedLimit a;

	cout<<endl<<a.journeyTime(100,v);
}
