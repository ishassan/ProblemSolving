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
#define repe(i,m,n) for(int i=(m); i<=(n); i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define rrepi(it,stl) for(typeof((stl).rbegin()) it = (stl).rbegin(); (it)!=stl.rend(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
using namespace std;

string check(string str){
	if(isupper(str[0]) || str[0]=='_' || str[sz(str)-1]=='_')
		return "Error";

	if(str.find("__") != -1)
		return "Error";

	bool score=0,cap=0;
	rep(i,sz(str)){
		if(str[i]=='_')
			score=1;
		else if(isupper(str[i]))
			cap=1;
	}

	if(score && cap)
		return "Error";
	else if(score)
		return "C";
	else if(cap)
		return "Java";
	else
		return "both";
}
int main() {

	string str;
	while(cin>>str){
		string chk = check(str);
		if(chk=="Error")
		{
			cout<<"Error!\n";
			continue;
		}

		if(chk=="Java"){
			rep(i,sz(str)){
				if(isupper(str[i])){
					str[i] = tolower(str[i]);
					str.insert(i,"_");
					i++;
				}
			}

		}

		else{
			rep(i,sz(str)-1){
				if(str[i]=='_'){
					str[i+1] = toupper(str[i+1]);
					str.erase(i,1);
					i--;
				}
			}
		}

		cout<<str<<endl;

	}

	return 0;
}
