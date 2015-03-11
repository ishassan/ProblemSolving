#include<iostream>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int size;
bool ismawgod(char x, char arr[])
{
for(int i=0;i<size;i++)
{
	if(arr[i]==x){
		arr[i]=' ';
		return 1;
	}
}
	return false;
}

void lowerCase(vector<string>& vstr){
	for(int i=0; i<vstr.size(); i++)
		for(int j=0; j<vstr[i].size(); j++)

			vstr[i][j] = tolower(vstr[i][j]);
}
int main() {
	vector<string> orig(100);
	vector<string> patt;
	vector<string> res;
	string tmp;
	while (cin >> tmp) {
		if (tmp == "#")
			break;
		patt.push_back(tmp);
	}
	copy(patt.begin() , patt.end() , orig.begin());

	lowerCase(patt);

	for (int n = 0; n < patt.size(); n++) {
		char check[20];
		for (int c = 0; c < patt[n].size(); c++) {
			char cur = patt[n][c];
			check[c] =cur;
		}
		size=patt[n].size();
		int n2;
		for (n2 = 0; n2 < patt.size(); n2++) { //names
			if (n2 == n)
				continue;//not count itself
			int c2;
			int count = 0;
			char temp[20];
			strcpy(temp,check);
			for (c2 = 0; c2 < patt[n2].size(); c2++) { //char
				char cur = patt[n2][c2];
				if (!ismawgod(cur,temp))
					break;

				count++;


			}
			if (count == patt[n2].size() && patt[n2].size() == patt[n].size())///the same
				break;

		}

		if (n2 == patt.size())
			res.push_back(orig[n]);

		else
			continue;
	}

	sort(res.begin(), res.end());
	for(int i=0; i<res.size();i++)
	cout<<res[i]<<endl;
	return 0;
}
