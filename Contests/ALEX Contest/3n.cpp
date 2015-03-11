#include <iostream>

using namespace std;

int main(){
	freopen("threen.in","rt",stdin);
     int tst = 1,n;
     while(cin>>n){
    	 if(n==0)
    		 return 0;
    	 cout<<tst++<<". ";
    	 while(n!=1){
    		 cout<<n<<" ";
    		 if(n%2==0)
    			 n /=2;
    		 else
    			 n = 3*n +1;
    	 }
    	 cout<<1<<endl;
     }
	return 0;
}
