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

int main() {

	int tst, n;
	cin >> tst;
	fo(t,tst) {
		cin >> n;
		int n1, n2, n3, n4;
		n1 = n3 = -1;

		foo(i,2,n) {
			if (n % i == 0 && i != n2) {
				if (n1 == -1)
					n1 = i, n2 = n / i;
				else {
					n3 = i, n4 = n / i;
					break;
				}
			}
		}

		printf("Case #%d: %d = %d * %d = %d * %d\n", t + 1, n, n1, n2, n3, n4);
	}

	return 0;
}
