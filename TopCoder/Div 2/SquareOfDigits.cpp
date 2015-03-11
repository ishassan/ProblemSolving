// TC SRM 439-D2-1	Points=117.3 of 250
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class SquareOfDigits {

public:
	int getMax(vector <string> data){
		int Max =1;
		string cur;
		int diff=0;
		for(int i=0; i<data.size(); i++){
			cur = data[i];

			//searching
			for(int j=0; j<cur.length(); j++){

				for(int k=j+1; k<cur.length(); k++){

					if(cur[j]==cur[k]){

						diff = k - j;

						if((i+diff)<data.size() && data[i+diff][j]==cur[j] && data[i+diff][k]==cur[k]){

							Max = max(Max,(diff+1)*(diff+1));
						}
					}

				}
			}
		}

		return Max;
	}



};

int main() {

	string test[] = {"9785409507",
			 "2055103694",
			 "0861396761",
			 "3073207669",
			 "1233049493",
			 "2300248968",
			 "9769239548",
			 "7984130001",
			 "1670020095",
			 "8894239889",
			 "4053971072"};
	 vector<string> v(test,test+sizeof(test)/sizeof(*test));


	SquareOfDigits x;

	cout<<x.getMax(v);

	return 0;
}
