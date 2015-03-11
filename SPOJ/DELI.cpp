#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

map<string, string> Map;
bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'y';
}
bool isspec(char str[102], int len) {
	if(len>=2)
		return str[len-1]=='o' || str[len-1]=='s' || str[len-1]=='x' || !strcmp(str+len-2,"sh")||!strcmp(str+len-2,"ch");
	if(len==1)
		return str[len-1]=='o' || str[len-1]=='s' || str[len-1]=='x';
	return 0;
}
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	char str[102], str2[102];
	while (n--) {
		scanf("%s %s", str, str2);
		Map[str] = str2;
	}
	while (m--) {
		scanf("%s", str);
		if (Map.find(str) != Map.end()) {
			printf("%s\n", Map[str].c_str());
			continue;
		}
		int len = strlen(str);
		if (str[len - 1] == 'y' && !isvowel(str[len - 2])) {
			strcpy(str + len - 1, "ies");
			printf("%s\n", str);
			continue;
		}
		if (isspec(str,len)) {
			strcat(str, "es");
			printf("%s\n", str);
			continue;
		}
		strcat(str, "s");
		printf("%s\n", str);
	}
	return 0;
}
