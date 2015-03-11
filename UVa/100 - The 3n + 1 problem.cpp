//UVa 100
#include <iostream>

using namespace std;

int cycle(int num) {
	int count = 1;
	while (num > 1) {

		if (num % 2 == 1)
			num = 3 * num + 1;

		else
			num /= 2;

		count++;
	}
	return count;
}
int main() {

	int min, max, best=0, ret;
	int num1,num2;
	while (cin >> num1 >> num2) {

		if(num1>num2){
			min = num2;
			max = num1;
		}

		else{
			min = num1;
			max = num2;
		}

			for(int i=min; i<=max; i++){

				ret = cycle(i);
				if(ret>best)
					best = ret;
			}


		cout<<num1<<" "<<num2<<" "<<best<<endl;

		best=0;


	}
	return 0;
}
