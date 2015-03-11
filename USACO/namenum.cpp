/*
 ID: fci_isl1
 LANG: C++
 PROB: namenum
 */
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main() {
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);

	map<char, char> m;
	char ind = '2';
	for (char i = 'A'; i < 'P'; i += 3)
		m[i] = m[i + 1] = m[i + 2] = ind++;

	m['P'] = m['R'] = m['S'] = '7';
	m['T'] = m['U'] = m['V'] = '8';
	m['W'] = m['X'] = m['Y'] = '9';

	ifstream file("dict.txt");
	string n, w;

	cin >> n;
	bool found=0;
	while (file) {
		file >> w;
		int sz = w.size();
		if (sz != n.size())
			continue;

		for (int i = 0; i < sz; i++)
			if (n[i] != m[w[i]])
				goto end;
		if (file){
			found =1;
			cout << w << endl;
		}
		end: ;
	}
	file.close();

	if(!found)
		cout<<"NONE\n";
	return 0;
}
