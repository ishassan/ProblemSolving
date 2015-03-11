#include<iostream>
#include<string>
using namespace std;

int cost[36];
char num[100];
int ans[36];
int cheapstBase(int n) {
	int sum = 0;
	int N = atoi(num);
	while (N != 0) {
		sum += cost[N % n];
		N /= n;
	}
	return sum;
}
int main() {
	int tst, tst2, len;
	int count = 1;
	cin >> tst;
	while (tst--) {
		if (count != 1)
			cout << endl;
		for (int i = 0; i < 36; i++)
			cin >> cost[i];
		cout << "Case " << count++ << ":" << endl;
		cin >> tst2;
		while (tst2--) {
			memset(ans, 0, sizeof(ans));
			cin >> num;
			cout << "Cheapest base(s) for number " << num << ":";
			int min = 1000000000;
			for (int i = 2; i < 37; i++) {
				ans[i] = cheapstBase(i);
				if (min > ans[i])
					min = ans[i];
			}
			for (int i = 2; i < 37; i++)
				if (ans[i] == min)
					cout << " " << i;
			cout << endl;
		}
	}
	return 0;
}
