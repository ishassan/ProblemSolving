//TC Real Contest: SRM 445 - Div2 - 1 , Points =  226.07
#include <iostream>
#include <string>
using namespace std;

class TheEncryptionDivTwo {

public:
	
	string encrypt(string message) {

		char a = 'a';
		//string msg = sort(message);
		string res;
		bool found = 0;
		int j;
		for(int i=0; i<message.length(); i++){

			for(j=0; j<i; j++){

				if(message[i]==message[j]){
			
					found=1;
					break;

				}
			}

			if(found)
			{
				res += res[j];
			}

			else
			{
				res += a;
				a++;
			}

			found = 0;

		}
				


		return res;
	}

};
int main() {

	//string arr[];
	//vector<string> v(arr,arr+sizeof(arr)/sizeof(*arr));

	TheEncryptionDivTwo a;

	cout<<a.encrypt("topcoder");	//abcdbefg

	cout<<endl;
	system("pause");
	return 0;
	
}

