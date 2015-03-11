// Problem   Decorate the wall
// Algorithm brute force
// Runtime   O(n^3)
// Author    Adrian Kuegel
// Date      2005.05.28

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;

#define MAXN 256

typedef set<int> SI;

int main() {
	int tc;
	cin >> tc;
	while(tc-- > 0) {
		int n,w,h;
		cin >> n >> w >> h;

		int x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN];
		// store all necessary x and y-values in a set
		// note that only boundary coordinates are required
		// The new painting must be bounded at the bottom and the left; otherwise,
		// there would be another position where it fits which is preferred
		SI allx, ally;
		allx.insert(0);
		ally.insert(0);
		// read the already hanging paintings
		for (int i=0; i<n; i++) {
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			// assert that there are no overlapping paintings

			allx.insert(x1[i]);
			allx.insert(x2[i]);
			ally.insert(y1[i]);
			ally.insert(y2[i]);
		}
		int needed_w, needed_h;
		cin >> needed_w >> needed_h;

		// brute force over possible lower left corners
		for (SI::iterator it2 = ally.begin(); it2 != ally.end(); it2++) {
			if (*it2 + needed_h > h)
				break;
			for (SI::iterator it = allx.begin(); it!=allx.end(); it++) {
				if (*it + needed_w > w)
					break;
				// check if there are any overlappings if current lower left corner is used
				for (int i=0; i<n; i++) {
					if (max(x1[i],*it)<min(x2[i],*it+needed_w)
					&&  max(y1[i],*it2)<min(y2[i],*it2+needed_h))
						break;
					if (i == n-1) { // if no already hanging painting overlaps, the corner
							// is a possible solution. Since the iteration is done
							// in increasing order of y, then x, it is the desired solution

						cout << *it << " " << *it2 << endl;
						goto done;
					}
				}
			}
		}
		cout << "Fail!" << endl;
		done:;
	}

	return 0;
}
