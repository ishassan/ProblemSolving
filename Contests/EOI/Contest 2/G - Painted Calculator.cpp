#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int amp[10] = { 30, 10, 25, 25, 20, 25, 30, 15, 35, 30 };
int memo[2002];

int toamp(int num) {
	int res = 0;
	while (num) {
		res += amp[num % 10];
		num /= 10;
	}
	return res;
}
int main() {

	int a, b, c;
	fo(i,10)
		memo[i + 1000] = amp[i];

	foo(i,10,1000)
		memo[i + 1000] = toamp(i);

	foo(i,-999,0)
		memo[i + 1000] = memo[(-1 * i) + 1000] + 5;

	while (cin >> a >> b >> c) {
		int res = 0;
		for (int i = -999; i < 1000; i++) {
			if (memo[i + 1000] != a)
				continue;

			for (int j = -999; j < 1000; j++) {
				if (memo[j + 1000] != b)
					continue;

				if (i + j < 1000 && i + j > -1000) {
					if (memo[i + j+1000] == c)
						res++;
				}

				if (i - j < 1000 && i - j > -1000) {
					if (memo[i - j+1000] == c)
						res++;
				}

				if (i * j < 1000 && i * j > -1000) {
					if (memo[i * j+1000] == c)
						res++;
				}

				if (j != 0 && i / j < 1000 && i / j > -1000) {
					if (memo[i / j+1000] == c)
						res++;
				}

			}
		}
		if (res == 1)
			printf("1 solution for %d %d %d\n", a, b, c);
		else if (res == 0)
			printf("No solutions for %d %d %d\n", a, b, c);
		else
			printf("%d solutions for %d %d %d\n", res, a, b, c);
	}

	return 0;
}
