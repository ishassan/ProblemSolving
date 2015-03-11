#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
#endif

	int n;
	while(cin >> n){
		int mx=0,seq,prev=-1e9;
		int totlen=0,curlen=0;
		bool flip=0;
		for (int i = 0; i < n; ++i){
			cin >> seq;
			if(seq >= prev){
				++totlen;
				if(flip) ++curlen;
			}
			else if(!flip){flip = 1; ++totlen; ++curlen;}
			else{
				mx = max(mx, totlen);
				totlen=curlen+1;
				curlen=1;
			}
			prev=seq;
		}
		mx = max(mx, totlen);
		cout << mx << "\n";

	}

	return 0;


}
