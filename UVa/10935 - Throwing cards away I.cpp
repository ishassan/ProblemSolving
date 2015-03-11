#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    // freopen("in.txt","rt",stdin);
    //freopen("out.txt","wt",stdout);
    int size;
    string one="Discarded cards:";
	string two="Remaining card:";
   while( cin>>size)
       { 
            if(size==1) { cout<<one<<endl<<two<<" 1"<<endl; continue;}
            if(size==0)return 0;
            vector<int>deck;
            vector<int>ret;
        	for(int i=1;i<=size;i++)
			deck.push_back(i);
			while(deck.size()>2)
			{
            ret.push_back(deck.front());
			deck.erase(deck.begin());
			int tmp1=deck.front();
			deck.erase(deck.begin());
			deck.push_back(tmp1);
            }
            cout<<one;
        for(int i=0;i<ret.size();i++)
			cout<<" "<<ret[i]<<",";
			cout<<" "<<deck[0]<<endl;
			cout<<two<<" "<<deck[1]<<endl;
    }
			
	
	return 0;
}
