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
#include <iomanip>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

string str1, str2;
int n1 = 0, n2 = 0;

const int SIZE = 10000;
string word1[SIZE], word2[SIZE];
int memo[SIZE][SIZE];

int lcs(int i, int j) {
	if (i >= n1 || j >= n2)
		return 0;

	if (memo[i][j] != -1)
		return memo[i][j];

	int igi = lcs(i + 1, j);
	int igj = lcs(i, j + 1);
	int match = lcs(i + 1, j + 1) + (word1[i] == word2[j]);

	return memo[i][j] = max(match, max(igi, igj));
}
int main() {

	int tst = 1;
	while (getline(cin, str1), getline(cin, str2)) {

		if (str1.size() == 0 || str2.size() == 0) {
			cout << setw(2) << tst++ << ". Blank!\n";
			continue;
		}

		string word;
		if (isalnum(str1[0]))
			word += str1[0];

		int ind = 0;
		foo(i,1,str1.size()) {
			if (isalnum(str1[i]))
				word += str1[i];

			else if (isalnum(str1[i - 1])) { //if the first punc
				word1[ind++] = word;
				word.clear();
			}
		}

		if(word.size()>0)
			word1[ind++] = word;

		n1 = ind;
		ind = 0;
		word.clear();

		if (isalnum(str2[0]))
			word += str2[0];

		foo(i,1,str2.size()) {
			if (isalnum(str2[i]))
				word += str2[i];

			else if (isalnum(str2[i - 1])) { //if the first punc
				word2[ind++] = word;
				word.clear();
			}
		}

		if(word.size()>0)
					word2[ind++] = word;

		n2 = ind;

		fo(i,n1)
			fo(j,n2)
				memo[i][j] = -1;

		cout << setw(2) << tst++ << ". Length of longest match: " << lcs(0, 0)
				<< endl;

		fo(i,n1)
			word1[i] = "";

		fo(i,n2)
			word2[i] = "";

	}

	return 0;
}

