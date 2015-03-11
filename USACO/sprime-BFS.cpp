/*
 ID: fci_isl1
 LANG: C++
 TASK: sprime
 */

#include <iostream>
#include <queue>
using namespace std;

#define mp(a,b) make_pair(a,b)

bool isprime(int n) {
	if (n == 2)
		return true;
	if (n < 2 || n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int digits[] = { 1, 3, 7, 9 };

void BFS(int n) {
	queue<pair<int, int> > q;
	q.push(mp(2,1)), q.push(mp(3,1)), q.push(mp(5,1)), q.push(mp(7,1));
	int num,dig;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			num = q.front().first;
			dig = q.front().second;
			q.pop();

			if(dig==n)
			{
				cout<<num<<endl;
				continue;
			}

			int test;
			for(int i=0; i<4; i++){
				test = num*10 + digits[i];
				if(isprime(test))
					q.push(mp(test, dig+1));
			}
		}
	}
}
int main() {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);

	int n;
	cin >> n;

	BFS(n);
	return 0;
}
