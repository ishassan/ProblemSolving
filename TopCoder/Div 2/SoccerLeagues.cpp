//TC 443-D2-1  Points = 170.01

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SoccerLeagues{

public: 
	vector <int> points(vector <string> matches){
		
		string cur;
		vector<int> res;
		for(int i=0; i<matches.size(); i++){
			
			cur = matches[i];
			res.push_back(0);
			for(int j=0; j<cur.length(); j++){
			
				if(cur[j]=='W')
					res[i] += 3;
				else if(cur[j]=='D')
					res[i] += 1;
			}

			for(int k=0; k<matches.size(); k++){

				if(k!=i){
				if(matches[k][i]=='L')
					res[i] += 3;

				else if(matches[k][i]=='D')
					res[i] +=1;
			
				}
			
			}
		
		}

		return res;


		}
	
};
int main() {

	SoccerLeagues a;

	string arr[] = {"-WW",
 "W-W",
 "WW-"};

	vector<string> x(arr,arr+sizeof(arr)/sizeof(*arr));
	a.points(x);
	

	cout<<endl;
	system("pause");
	return 0;
}
