//UVa 10699
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;


int main() {

	int n;
	while(1){

		cin>>n;

		if(n==0)
			break;


		if(n<2)
		{
			cout<<n<<" : "<<0<<endl;
			continue;
		}

		int count=0;

		int nVal =n;

		//special case (2) for being even number
		if(n%2==0){
			count++;

			while(n%2==0)
				n /=2;
		}

		for(int i=3; i*i<=n; i+=2){

			if(n%i==0){
				count++;

				while(n%i==0)
					n /=i;
			}
		}

		if(n>1)		//if the remainder is prime
			count++;

		cout<<nVal<<" : "<<count<<endl;

	}

	return 0;
}
