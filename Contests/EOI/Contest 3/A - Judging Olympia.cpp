#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <numeric>
#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)

using namespace std;

int arr[6];
int main() {

	while (1) {
		bool b = 0;
		fo(i,6) {
			cin >> arr[i];
			if (arr[i] != 0)
				b = 1;
		}
		if (!b)
			return 0;

		sort(arr,arr+6);
		double res = 0;
		foo(i,1,5)
			res += arr[i];
		cout << res / 4 << endl;
	}

	return 0;
}
