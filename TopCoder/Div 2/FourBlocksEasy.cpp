//TC 444-D2-1  Points = 249.97

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FourBlocksEasy{

public:
	int maxScore(vector<string> grid){

		string raw1=grid[0],raw2=grid[1];

		unsigned short int score=0;

		for(unsigned short int i=0; i<raw1.length(); i++){

			if(raw1[i]=='.' &&
				raw1[i+1]=='.' &&
				raw2[i]=='.' &&
				raw2[i+1]=='.'){

					score+=16;
					i++;

				}


			else{
				score+=2;

			}
		}

		return score;
	}

};
int main() {

	FourBlocksEasy x;
	string a[] = {".",
			      "."};
	vector<string> v(a, a + 2);

	cout<<x.maxScore(v);


	return 0;
}
