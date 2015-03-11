/*
 ID: fci_isl1
 LANG: C++
 TASK: preface
 */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int num[7] = { 1, 5, 10, 50, 100, 500, 1000 };
char letters[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int res[7] = {0};

int isfound(int n) {
	for (int i = 0; i < 7; i++)
		if (num[i] == n)
			return i;
	return -1;
}

bool ispower10(int n) {
	while (n > 1) {
		if (n % 10 > 0)
			return 0;
		n /= 10;
	}
	return 1;
}
string toRoman(int n, string str) {
	if (n == 0)
		return str;
	if (isfound(n) != -1) {
		int ind = isfound(n);
		return str + letters[ind];
	}

	int i;
	for (i = 0; i < 7; i++)
		if (num[i] > n)
			break;

	if (num[i] > n) {
		int diff;
		if (ispower10(num[i])) {
			diff = num[i] - num[i - 2];
			if (diff <= n && isfound(diff) == -1)
				return toRoman(n - diff, str + letters[i - 2] + letters[i]);
			return toRoman(n - num[i - 1], str + letters[i - 1]);
		}

		else{
			diff = num[i] - num[i-1];
			if(diff <=n && isfound(diff)==-1)
				return toRoman(n-diff, str+letters[i-1]+letters[i]);
			return toRoman(n - num[i - 1], str + letters[i - 1]);
		}

	}

	else
		return toRoman(n - 1000, str + 'M');

}
int main() {
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);

	int N;
	cin>>N;
	for(int i=1; i<=N; i++){
		string str = toRoman(i,"");

		for(int j=0; j<str.size(); j++)
			for(int k=0; k<7; k++)
				if(str[j]==letters[k])
					res[k]++;
	}

	for(int i=0; i<7; i++)
		if(res[i]>0)
			cout<<letters[i]<<" "<<res[i]<<endl;


	return 0;
}
