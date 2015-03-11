#include <iostream>
#include <string>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,j,n) for(int i=j;i<(n);++i)
#define mp(a,b) make_pair(a,b)


int removed(int last, int cur, int next,string str) {
	if (cur > 11 || cur < -1)
		return 0;

	string cpy = str;

	//ToRight
	int c1 = 0;
	if (next < 11 && str[cur] == 'o' && str[next] == 'o' && str[next + 1]
			== '-')
		str[cur] = str[next] = '-', str[next + 1] = 'o', c1 = 1 + removed(-1,
				0,  1,str);

	//ToLeft
	str = cpy;
	int c2 = 0;
	if (last > 0 && str[last - 1] == '-' && str[last] == 'o' && str[cur] == 'o')
		str[last - 1] = 'o', str[last] = str[cur] = '-', c2 = 1 + removed(-1,
				0,  1,str);

	str = cpy;
	int c3 = removed(cur,next, next + 1,str);

	return  max(max(c1,c2),c3);
}
int main() {

	string str;
	int tst, tot;
	scanf("%d", &tst);
	while (tst--) {
		tot = 0;
		cin>>str;
		fo(i,12)
			if (str[i] == 'o')
				tot++;

		printf("%d\n", tot-removed(-1, 0, 1,str));
	}

	return 0;
}
