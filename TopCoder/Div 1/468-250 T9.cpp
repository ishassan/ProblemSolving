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
#include <sys/types.h>
#include <dirent.h>
#include <fstream>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define find(v,x) (find(all((v)),(x))-(v).begin())
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;



int main()
{
    freopen("out.txt","wt",stdout);

    DIR* dir = opendir("/media/Work/workspace/SRM/");
    dirent* file;
    while(file = readdir(dir)){
        string name(file->d_name);
        if((sz(name) >= 2 && name.substr(sz(name)-2)==".o") || name[sz(name)-1]=='~'){
            name = "/media/Work/workspace/SRM/" + name;
            remove(name.c_str());
            cout << name <<" is removed\n";
            continue;
        }
        if(!isdigit(name[0])) continue;
        int idx = search_n(all(name),1,'-') - name.begin();
        if(idx == sz(name)) continue;
        string from = "/media/Work/workspace/SRM/" + name,to;
        ifstream in;
        in.open(from.c_str());

        ofstream out;
        if(isdigit(name[idx+1])){
            to = "/media/Work/ACM/TopCoder/Div 1/" + name;
            out.open(to.c_str());
        }
        else{
            to = "/media/Work/ACM/CodeForces/" + name;

            out.open(to.c_str());
        }
        out << in.rdbuf();
        cout << from <<" => " << to << endl;
        out.close();
        in.close();
        remove(from.c_str());
    }

    return 0;
}