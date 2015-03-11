#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

void lower(string& str) {
	int sz = str.size();
	fo(i,sz)
		str[i] = tolower(str[i]);
}

void upper(string& str) {
	int sz = str.size();
	fo(i,sz)
		str[i] = toupper(str[i]);
}

vs lineToWords(string line) {//divide line to words
	vs words;
	string str;
	fo(i,line.size()) {
		if (!isalpha(line[i])) {
			words.push_back(str);
			str.clear();
		} else
			str += line[i];

	}
	words.push_back(str);
	return words;
}

void sort(vector<pair<string, string> >& keys, int sz) {

	fo(i,sz) {
		pair<string,string> mnp = keys[i];
		int mi=-1;
		foo(j,i+1,sz) {

			if (mnp.first> keys[j].first)
				mnp = keys[j], mi=j;
		}
		if(mi>-1){
		keys.erase(keys.begin()+mi);
		keys.insert(keys.begin()+i,1,mnp);
		}
	}
}


int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	map<string, bool> ignore;
	vector<pair<string, string> > keys; //keys,titles
	string str;

	while (cin >> str) {
		if (str == "::")
			break;
		ignore[str] = 1;
	}
	getline(cin, str); //to drop \n

	while (getline(cin, str)) {

		lower(str);
		vs wrds = lineToWords(str);
		int sz = wrds.size();
		int lastInd=0;
		fo(i,sz) {
			if (ignore[wrds[i]] == 0) {
				string wrd = wrds[i];
				int pos = str.find(wrd,lastInd);
				upper(wrd);
				string strc = str;
				strc.replace(pos,wrd.size(),wrd);
				keys.push_back(mp(wrd,strc));
				lastInd = pos+1;
			}
		}

	}

	int sz = keys.size();
	sort(keys, sz);

	fo(i,sz){
		cout << keys[i].second<<endl;

	}
	return 0;
}
