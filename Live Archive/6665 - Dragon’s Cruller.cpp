#include <bits/stdc++.h>
#include <hash_map>
#define sz(v) (int)(v).size()
#define mp(a,b) make_pair((a),(b))
using namespace std;
using namespace __gnu_cxx;

vector<vector<int> > g(3, vector<int>(3));
const int mod = 1000000007;
struct hashf {
	int operator()(const long long x) const {
		return x % mod;
	}
};

void setNum(int i, int j, long long val, long long &bit){
	int idx = i*3+j;
	bit&= (~(15LL << (idx*4)));
	bit|= (val<<(idx*4));
}
long long compress() {
	long long res = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			setNum(i,j,g[i][j], res);
		}
	}
	return res;
}

int getNum(int i, int j, long long bit){
	int idx = i*3+j;
	return (bit>>(idx*4))&15;
}

pair<int, int> decompress(long long bit) {
	pair<int, int> zero;
	for (int i = 2; i >= 0; --i) {
		for (int j = 2; j >= 0; --j) {
			g[i][j] = getNum(i,j,bit);
			if (g[i][j] == 0)
				zero = mp(i, j);
		}
	}
	return zero;
}


int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

int ch, cv;
int dist[500000];
int children[1000000][4];
//map<long long,long long> par;

hash_map<long long, int,hashf> rnk;
long long toBit[1000000];
int getRank(long long bit) {
	int sz = rnk.size();
	if(rnk.find(bit) == rnk.end()){
		rnk[bit] = sz;
		toBit[sz] = bit;
	}
	return rnk[bit];
}
long long start, goal;
int dij(int start,int goal) {
	if (start == goal)
		return 0;

	//cst, bit graph
	priority_queue<pair<int, int>, vector<pair<int, int> >,
	greater<pair<int, int> > > q;
	q.push(mp(0, start));
	memset(dist,0x3f,sizeof(dist));
	dist[start] = 0;
	while (q.size()) {
		int cst = q.top().first;
		start = q.top().second;
		q.pop();

		if (cst != dist[start])
			continue;

		if (start == goal)
			return cst;


		//      cout <<"PARENT: " << cst << "\n";
		//
		//      for (int i = 0; i < 3; ++i) {
		//          for (int j = 0; j < 3; ++j) {
		//              cout << g[i][j] << " ";
		//          }
		//          cout <<"\n";
		//      }
		//      cout <<"\n";

		for (int d = 0; d < 4; ++d) {

			int CH = children[start][d];
			int nwcst = cst + ((d == 0 || d == 2) ? cv : ch);

			//          cout <<"CHILD " << nwcst <<"\n";
			//
			//          for (int i = 0; i < 3; ++i) {
			//              for (int j = 0; j < 3; ++j) {
			//                  cout << g[i][j] << " ";
			//              }
			//              cout <<"\n";
			//          }
			//          cout <<"\n";
			if (dist[CH] <= nwcst)
				continue;
			//          par[nwbit] = bit;
			dist[CH] = nwcst;
			q.push(mp(nwcst, CH));
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	//  freopen("out.txt","wt",stdout);
#endif
	int arr[9]={0,1,2,3,4,5,6,7,8};
	do{
		long long bit = 0;
		pair<int,int> zero;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++){
				int idx = i*3+j;
				setNum(i, j, arr[idx], bit);
				if(arr[idx]==0) zero=mp(i,j);
			}
		int id = getRank(bit);
		for (int d = 0; d < 4; ++d) {
			int ni = zero.first + di[d];
			int nj = zero.second + dj[d];

			if (nj < 0) {
				nj = 2;
				ni = (ni - 1 + 3) % 3;
			} else if (nj > 2) {
				nj = 0;
				ni = (ni + 1) % 3;
			}
			if (ni < 0)
				ni = 2;
			else if (ni > 2)
				ni = 0;

			long long nwbit = bit;
			setNum(ni,nj,0,nwbit);
			setNum(zero.first,zero.second, getNum(ni,nj,bit),nwbit);
			children[id][d] = getRank(nwbit);
		}

	}while(next_permutation(arr,arr+9));

	while (cin >> ch >> cv && (ch || cv)) {
		//      par.clear();
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> g[i][j];
		start = compress();
		//      par[start] = -1;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> g[i][j];
		goal = compress();
		cout << dij(getRank(start), getRank(goal)) << "\n";
		//      while(goal != -1){
		//          decompress(goal);
		//          cout << "COST: " << dist[goal]<<"\n";
		//          for (int i = 0; i < 3; ++i) {
		//              for (int j = 0; j < 3; ++j) {
		//                  cout << g[i][j] << " \n"[j==2];
		//              }
		//          }
		//          goal = par[goal];
		//          cout << "\n\n";
		//      }
	}

}
