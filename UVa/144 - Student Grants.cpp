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

using namespace std;

const int VAL = 40;
int main() {


	int n, k;
	while (cin >> n >> k) {
		if (n == 0 && k == 0)
			break;

		if (k == 1) {
			n++;
			foo(i,1,n)
				cout << setw(3) << i;
			cout<<endl;
			continue;
		}

		if (n == 1) {
			cout << setw(3) << 1 << endl;
			continue;
		}

		if(n==0){
			cout<<endl;
			continue;
		}
		vector<pair<int, int> > res(n);//value, rank

		fo(i,n)
			res[i] = make_pair(0,i+1);

		int ind = 0;
		int rest = 0, money = 0;
		for (int i = 1;; i++) {

			if (i > k)
				i = 1;

			if (ind == res.size())
				ind = 0;

			if (rest > 0) {
				money = rest;
				rest = 0;
				i--;
			} else
				money = i;

			res[ind].first += money;
			if (res[ind].first >= VAL) {

				rest = (res[ind].first) - VAL;
				cout << setw(3) << res[ind].second;
				res.erase(res.begin() + ind); //ind++ here
				if (res.size() == 0)
					break;
			} else
				ind++;

		}
		cout << endl;
	}
	return 0;
}
