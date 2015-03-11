//TC 442-D2-1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SimpleWordGame {

public:
	int points(vector<string> player, vector<string> dictionary) {

		string current;
		bool found = 0;
		int result = 0;

		for (unsigned int i = 0; i < player.size(); i++) {
			current = player[i];

			//searching the dictionary
			for (unsigned int j = 0; j < dictionary.size(); j++) {

				if (current == dictionary[j]) { //The word was found in the dictionary

					//check if it is written before in "player"
					for (unsigned int k = 0; k < i; k++) {
						if (current == player[k]) {
							found = 1;
							break;
						}

					}

					if (!found)
						result += current.length() * current.length();

					found = 0;
					break;
				}
			}

		}

		return result;
	}

};

int main() {

	SimpleWordGame a;
	vector<string> p, d;

	p.push_back("lidi");
	p.push_back("o");
	p.push_back("lidi");
	p.push_back("gnbewjzb");
	p.push_back("kten");
	p.push_back("ebnelff");
	p.push_back("gptsvqx");
	p.push_back("rkauxq");
	p.push_back("rkauxq");
	p.push_back("kfkcdn");

	d.push_back("nava");
	d.push_back("wk");
	d.push_back("kfkcdn");
	d.push_back("lidi");
	d.push_back("gptsvqx");
	d.push_back("ebnelff");
	d.push_back("hgsppdezet");
	d.push_back("ulf");
	d.push_back("rkauxq");
	d.push_back("wcicx");


	cout << a.points(p, d);

	return 0;
}
