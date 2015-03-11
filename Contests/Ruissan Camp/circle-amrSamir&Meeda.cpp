#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
using namespace std;
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;

int n;
int p1, p2, p3, p4;

bool notsorted(vector<int>& nums) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (nums[i] > nums[j])
			cnt++;
	}
	return cnt > 1;
}

vector<int> solve1(vector<int> nums, bool bubbleLeft, bool sortLeft, int ind) {
	vector<int> res;
//	cerr << (int)(find(nums.begin(), nums.end(), 1)-nums.begin()) << endl;
	if (sortLeft) {
		while (nums[ind] != 1) {
			int t = nums[p4];
			res.push_back(t);
			for (int j = p4 + 1; j < n; j++) {
				res.push_back(nums[j]);
				nums[j - 1] = nums[j];
			}
			res.push_back(t);
			nums[p3] = t;
		}
	} else {
		while (nums[ind] != 1) {
			int t = nums[p3];
			res.push_back(t);
			for (int j = p3 - 1; j >= 0; j--) {
				res.push_back(nums[j]);
				nums[j + 1] = nums[j];
			}
			res.push_back(t);
			nums[p4] = t;
		}
	}
	cerr << res.size() << endl;
	while (notsorted(nums)) {
		// swap at N/2
		if (nums[p2] != 1 && nums[p1] != 1 && nums[p1] > nums[p2]) {
			res.push_back(nums[p1]);
			res.push_back(nums[p2]);
			res.push_back(nums[p1]);
			swap(nums[p1], nums[p2]);
		}
		// swap at N
		if (nums[p4] != 1 && nums[p3] != 1 && nums[p3] > nums[p4]) {
			res.push_back(nums[p3]);
			res.push_back(nums[p4]);
			res.push_back(nums[p3]);
			swap(nums[p3], nums[p4]);
		}
		if (!notsorted(nums))
			break;
		if (bubbleLeft) {
			int t = nums[p4];
			res.push_back(t);
			for (int j = p4 + 1; j < n; j++) {
				res.push_back(nums[j]);
				nums[j - 1] = nums[j];
			}
			res.push_back(t);
			nums[p3] = t;
		} else {
			int t = nums[p3];
			res.push_back(t);
			for (int j = p3 - 1; j >= 0; j--) {
				res.push_back(nums[j]);
				nums[j + 1] = nums[j];
			}
			res.push_back(t);
			nums[p4] = t;
		}
	}
	int oneI;
	for (int i = 0; i < n; ++i) {
		if( nums[i] == 1 )
			oneI = i;
	}
	if (oneI<=p1) {
		while (nums[0] != 1) {
			int t = nums[p4];
			res.push_back(t);
			for (int j = p4 + 1; j < n; j++) {
				res.push_back(nums[j]);
				nums[j - 1] = nums[j];
			}
			res.push_back(t);
			nums[p3] = t;
		}
	} else {
		while (nums[0] != 1) {
			int t = nums[p3];
			res.push_back(t);
			for (int j = p3 - 1; j >= 0; j--) {
				res.push_back(nums[j]);
				nums[j + 1] = nums[j];
			}
			res.push_back(t);
			nums[p4] = t;
		}
	}
//	for (int i = 0; i < n; ++i) {
//		assert(nums[i] == i+1);
//	}
	return res;
}
int main() {
	freopen("circle.in", "rt", stdin);
	freopen("circle.out","wt",stdout);
	cin >> n;
	vector<int> circ(n);
	for (int i = 0; i < n; ++i) {
		cin >> circ[i];
	}
	p1 = n / 2 - 1;
	p2 = n / 2;
	p3 = n - 1;
	p4 = 0;
//	for (int i = 0; i < n; ++i) {
	vector <int> res;
	int minV = (int)1e9;
	int i1 = (p2+p3+1)/2;
	int i2 = (p1+1)/2;
		vector<int> moves = solve1(circ, 0, 0, i1);
		if( minV > (int) moves.size())
			res = moves, minV = moves.size();
		moves = solve1(circ, 0, 0, i2);
				if( minV > (int) moves.size())
					res = moves, minV = moves.size();
		cerr << moves.size() << endl;
		moves = solve1(circ, 0, 1, i1);
		if( minV > (int) moves.size())
			res = moves, minV = moves.size();
		moves = solve1(circ, 0, 1, i2);
				if( minV > (int) moves.size())
					res = moves, minV = moves.size();
		cerr << moves.size() << endl;
		moves = solve1(circ, 1, 0, i1);
		if( minV > (int) moves.size())
			res = moves, minV = moves.size();
		moves = solve1(circ, 1, 0, i2);
				if( minV > (int) moves.size())
					res = moves, minV = moves.size();
		cerr << moves.size() << endl;
		moves = solve1(circ, 1, 1, i1);
		if( minV > (int) moves.size())
			res = moves, minV = moves.size();
		moves = solve1(circ, 1, 1, i2);
				if( minV > (int) moves.size())
					res = moves, minV = moves.size();
		cerr << moves.size() << endl;
//		cout << i << " " << i2 << " " << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) {
		if (i)
			printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
//	}
	return 0;
}
