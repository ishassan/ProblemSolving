//UVa 583
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define lng long long

int main() {

	lng n;

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		cout<<n<<" = ";

		vector<int> res;
		if (n < 0) {
			n *= -1;
			res.push_back(-1);
		}

		while(n%2==0){
			res.push_back(2);
			n /=2;
		}

		for (lng i = 3; i * i <= n; i += 2) {

			while (n % i == 0) {
				res.push_back(i);

				n /= i;

			}
		}

		if (n > 1)
			res.push_back(n);

		//display result
		int size = res.size();
		for(int i=0; i<size; i++){

			cout<<res[i];
			if(i+1 < size)
				cout<<" x ";
		}
		cout << endl;

	}

	return 0;
}
