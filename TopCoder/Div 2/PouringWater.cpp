// TC SRM 439-D2-2	Points=499.39
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PouringWater {

public:
	int getMinBottles(int N, int K){

		vector<int> n;

		int plus = 0;
		int length =0;
		int next=0;
		n.push_back(N);

		for(int i= 0;n[i]/2!=0;i++){
			n.push_back(n[i]/2);
			n[i] = n[i] % 2;
		}



		for(int i=0; i<n.size(); i++){
			if(n[i]!=0)
				length++;
		}


		if(length>K){
			for(int j=2,i=1; i<n.size(); i++,j*=2){
				n[i] *= j;
			}


			for(next=1;n[next]==0; next++);
			plus = n[next] - n[0];
		}

		return plus;
	}


};

int main() {

	/*string test[] = {"aaa","aaa"};
	 vector<string> v(test,test+sizeof(test)/sizeof(*test));
	 */

	PouringWater a;

	cout<<a.getMinBottles(3, 3);

	return 0;
}
