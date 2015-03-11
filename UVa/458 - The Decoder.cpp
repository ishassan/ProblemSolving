// UVa 458
#include <iostream>

using namespace std;



int main() {

	char x;

	while((x=getchar())!=EOF){
		if(x=='\n')
			putchar('\n');

		else
			putchar(x-7);
	}

	return 0;
}
