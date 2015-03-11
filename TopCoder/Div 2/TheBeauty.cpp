// TC SRM 437-D2-1	Points= 237.59 of 250	Time: 6 m
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class  TheBeauty{

public:
	int find(int n){

		int ret=1;
		bool f=0;
		string txt;
		stringstream out;
		out<<n;
		txt = out.str();

		for(int i=1; i<txt.length(); i++){

			for(int j=0; j<i; j++){
				if(txt[i]==txt[j]){
					f=1;
					break;
				}
			}

			if(!f)
				ret++;


			f=0;
		}

		return ret;


	}



};

int main() {

	/*int test[] = {3, 7, 12, 18, 25, 100, 33, 1000}

	;
	 vector<int> v(test,test+sizeof(test)/sizeof(*test));
*/


	TheBeauty a;

	cout<<endl<<a.find(100) ;



	return 0;
}
