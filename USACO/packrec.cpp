/*
 ID: fci_isl1
 LANG: C++
 TASK: packrec
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > res;
int h[4], w[4], mh, mw, minArea = 10000000; //mh=maxHeight
void test();

void generate(int i) {
	if (i == 4) {
		test();
		return;
	}

	generate(i + 1);
	swap(h[i], w[i]);
	generate(i + 1);
}

int main() {
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);

	pair<int, int> arr[4];

	for (int i = 0; i < 4; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + 4);

	do {
		for (int i = 0; i < 4; i++)
			h[i] = arr[i].first, w[i] = arr[i].second;

		generate(0);

	} while (next_permutation(arr, arr + 4));

	sort(res.begin(), res.end());
	cout << minArea << endl;

	int sz = res.size();
	for (int i = 0; i < sz; i++)
		cout << res[i].first << " " << res[i].second << endl;

	return 0;
}

inline int max(int a, int b) {
	return (a > b) ? a : b;
}

inline int max3(int a, int b, int c) {
	return max(a, max(b, c));
}

inline int max4(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));
}

inline int min(int a, int b) {
	return (a < b) ? a : b;
}

bool found(pair<int, int>& p) {
	int sz = res.size();
	for (int i = 0; i < sz; i++)
		if (res[i] == p)
			return 1;
	return 0;
}

void check() {
	pair<int, int> p = make_pair(min(mh, mw), max(mh, mw));
	int area = mh * mw;

	if (area < minArea) {
		minArea = area;
		res.clear();
		res.push_back(p);
	}

	else if (area == minArea)
		if (!found(p))
			res.push_back(p);
}

void test() {
	//case 1
	mh = max4(h[0], h[1], h[2], h[3]);
	mw = w[0] + w[1] + w[2] + w[3];
	check();

	//case 2
	mh = h[0] + max3(h[1], h[2], h[3]);
	mw = max(w[0], w[1] + w[2] + w[3]);
	check();

	//case 3
	mh = max(h[0], h[1] + max(h[2], h[3]));
	mw = w[0] + max(w[1], w[2] + w[3]);
	check();

	//case 4
	mh = max3(h[0], h[1] + h[2], h[3]);
	mw = w[0] + max(w[1], w[2]) + w[3];
	check();

	//case 6
	//3 0
	//2 1

	mh = max(h[0] + h[1], h[2] + h[3]);

	if (h[1] <= h[2])
		mw = max3(w[0] + w[3], w[1] + w[2], w[0] + w[2]);

	else
		mw = max3(w[0] + w[3], w[1] + w[2], w[1] + w[3]);

	check();

}
