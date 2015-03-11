//UVa 488
#include <iostream>

using namespace std;

int main() {

	int num, freq, amp;
	int count = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> amp;
		cin >> freq;
		count =0;
		//printing
		while (count < freq) {


			for (int j = 1; j < amp + 1; j++) {
				for (int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
			}

			for (int j = amp - 1; j > 0; j--) {
				for (int k = j; k > 0; k--) {
					cout << j;
				}
				cout << endl;
			}

			if ( (count + 1) < freq)
				cout << endl;

			count++;

		}

		if(i+1<num)
			cout<<endl;
	}

	return 0;
}
