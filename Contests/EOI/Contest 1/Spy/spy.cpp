#include <map>
#include <set>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <fstream>
using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,s,m) for(int i=s;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define PI = (2.0 * acos(0.0));
typedef stringstream ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
#define OO ((int)1e9)

int n , m , spy;
bool graph[155][155];

void numS(int x , int y)
{
   if( x ==  n-1 && y == m-1) return;
   for(int i = x ; i <  n ; i++)
   {
     for(int j = y ; j < m ; j++)  
       if(graph[i][j])
       {
          graph[i][j] = 0;
          spy--;
          return numS(i,j);
       }
   }
}

int main()
{

   // freopen("spy.in", "rt", stdin);
   // freopen("output.txt", "wt", stdout);
   // ofstream fout("input.txt");
    cin>>n>>m;
   // 	fout<<n<<' '<<m<<endl;
      char c;
      int cnt = 0;
      spy = 0;
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
          cin>>c;
          graph[i][j] =  (c == 'x') ;
          spy+=(c == 'x');
        }
   //   fout<<endl;
      }

    //  fout<<endl;
      while(spy!=0)
      {
         numS(0,0);
         cnt++;
      }
      cout<<cnt<<endl;

  //  system("pause");
    return 0;
}
