//TC 238-D2-1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ArrayHash {
public:
	int getHash(vector<string> input) {
		unsigned int hash = 0;
		string cur;
		int alpha; //alphaPosition

		for (unsigned int i = 0; i < input.size(); i++) {
			cur = input[i];
			for (unsigned int j = 0; j < cur.length(); j++) {
				alpha = cur[j] - 'A';

				hash += alpha + i + j;

				//alpha = Alphabet Position, i = Element of input, j =Position in Element
			}
		}

		return hash;
	}
};
int main() {

	ArrayHash x;
	vector<string> v;
	v.push_back("CBA");
	v.push_back("DDD");

	cout << x.getHash(v);

	return 0;
}
