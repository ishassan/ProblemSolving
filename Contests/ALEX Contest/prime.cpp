#include <iostream>
#include <map>
using namespace std;
map<int,bool> primes;
bool isprime(int n){
	if(n==2)
		return 1;
	if(n<2 || n%2==0)
		return 0;

	for(int i=3; i*i<=n; i+=2){
		if(n%i==0)
			return 0;
	}
	return 1;

}
int main(){
	freopen("prime.in","rt",stdin);


	int first,last, count=1;
	while(cin>>first>>last){
		if(first==0 && last ==0)
			return 0;
		cout<<count++<<".";

		for(int i=first; i<=last; i++){
			if(primes[i]==0)
				primes[i]=isprime(i);

			if(primes[i])
				cout<<" "<<i;
		}
		cout<<endl;
	}

	return 0;
}
