// TC SRM 438-D2-1	Points=128.38 of 250	Time:35 m
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class  UnluckyNumbers{

public:

	void sort (vector<int> & v){
		char temp;

		for(int i=0; i<v.size(); i++){
			for(int j=i+1; j<v.size(); j++){

				if(v[i]>v[j]){
					temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
	}

	int getCount(vector <int> luckySet, int n){

		sort(luckySet);

		int i;
		int ret = 0;
		int start,end;

		for(i=luckySet.size()-1; i>-1; i--){
			if(n==luckySet[i])
				return 0;

			else if(n>luckySet[i])
				break;
		}



		if(i==-1)
			return 0;


		start = luckySet[i]+1;
		end = luckySet[i+1];

		for(i = start; i<end; i++){
			for(int j = start + 1; j<end; j++)

				if(i !=j  && n>=i && n<= j){
				ret++;
				cout<<i<<" "<<j<<endl;
				}
		}

		return ret;

	}




};

int main() {

	int test[] = {3, 7, 12, 18, 25, 100, 33, 1000}

	;
	 vector<int> v(test,test+sizeof(test)/sizeof(*test));



	UnluckyNumbers a;

	cout<<endl<<a.getCount(v,59);

	return 0;
}
