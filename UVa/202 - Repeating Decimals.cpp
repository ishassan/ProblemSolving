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
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

//-------------------------------
const int MAX = 3001;
const int MIN = 1501;
void print(int ans[], int start, int end) {

	fo(i,start)
		cout << ans[i];
	cout << "(";

	int len = end - start;

	if (len > 49) {
		fo(i,50)
			cout<<ans[start++];
		cout << "...";
	}

	else{
	foo(i,start,end)
		cout << ans[i];
	}
	cout << ")\n";
	cout << "   " << len
			<< " = number of digits in repeating cycle\n\n";
}

bool isRepeated(int ans[], int start, int len) {
	int sz = MAX;

	bool rep = 0;
	int beg = start + len;
	while (1) {

		if (beg + len >= sz)
			return rep;

		fo(i,len) {
			if (ans[start++] != ans[beg++])
				return 0;
		}

		rep = 1;
	}

}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int d;
	while (cin >> n >> d) {
		int ans[MAX];
		int rem;
		cout << n << "/" << d << " = " << n / d << ".";
		vector<vector<int> > mat(11);
		int num;
		fo(i,MAX) {
			rem = n % d;
			n = rem * 10;
			num = n / d;
			mat[num].push_back(i);
			ans[i] = num;
		}

		fo(i,MIN) {
			num = ans[i];

			int sz = mat[num].size();
			foo(k,0,sz) {
				int j = mat[num][k];
				if (j <= i)
					continue;

				//seq: start = i , end = j
				int len = j - i;

				if (isRepeated(ans, i, len)) {
					print(ans, i, j);
					goto outLoops;
				}

			}
		}
		outLoops: ;

	}
	return 0;
}
