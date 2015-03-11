/*
ID: fci_isl1
LANG: C++
PROB: milk
*/
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
 freopen("milk.in","r",stdin);
 freopen("milk.out","w",stdout);
  
  int n,m;
  cin>>n>>m;
  vector<pair<int,int> > v(m);
 
  for(int i=0; i<m; i++){
     cin>>v[i].first>>v[i].second;                
  }
  
  sort(v.begin(),v.end());
  int ret =0;
  for(int i=0; i<m; i++){
         if(v[i].second < n){
              ret += v[i].second* v[i].first;
              n -= v[i].second;          
         } 
         else{
              ret += n* v[i].first;
              break;
              }
  }
  cout<<ret<<endl;
  

 return 0;   
}
