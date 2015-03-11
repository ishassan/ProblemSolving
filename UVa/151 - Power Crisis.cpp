#include<iostream>
#include<list>
using namespace std;

int N;
int PowerCrisis(int m) {
	list<int> region;
	for (int i = 1; i <= N; i++)
		region.push_back(i);
	while (region.size() > 1) {
		region.pop_front();
		for (int i = 1; i < m; i++) {
			region.push_back(region.front());
			region.pop_front();
		}
	}
	return region.front();
}
int main() {
	while (cin >> N) {
		if (N == 0)
			break;
		int m = 1;
		int ans;
		while (true) {
			ans = PowerCrisis(m);
			if (ans == 13)
				break;
			m++;
		}
		cout << m << endl;
	}
	return 0;
}
