/*
ID: b2lawa1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<algorithm>
using namespace std;
int step[9][9]={ {0,1,-1,3,4,-1,-1,-1,-1},
                 {0,1,2,-1,-1,-1,-1,-1,-1},
                 {-1,1,2,-1,4,5,-1,-1,-1},
                 {0,-1,-1,3,-1,-1,6,-1,-1},
                 {-1,1,-1,3,4,5,-1,7,-1},
                 {-1,-1,2,-1,-1,5,-1,-1,8},
                 {-1,-1,-1,3,4,-1,6,7,-1},
                 {-1,-1,-1,-1,-1,-1,6,7,8},
                 {-1,-1,-1,-1,4,5,-1,7,8}   };
int rep[9];
int n_arr[9];
int arr[9];
int path[9];
bool go(int x)
{
     if(x<0) 
     {
             for(int i=0;i<9;i++)n_arr[i]=arr[i];
             for(int i=0;i<9;i++)
             {
                 for( int j=0;j<9;j++)
                 {
                           if(step[i][j]!=-1)  n_arr[j]=(n_arr[j]+(rep[i]*3))%12;
                 }
             }
             if(count(n_arr,n_arr+9,0)== 9)
              { 
                                         for(int i=0;i<9;i++)path[i]=rep[i]; 
                                         return true;
              }
             return false;
     }
     for(int y=0;y<4;y++)
     {
            rep[x]=y;
            if( go(x-1)==true){break;}
     }
     return false ;
}

int main()
{
    //freopen("in.txt","rt",stdin);
     //freopen("out.txt","w",stdout);
     freopen("clocks.in","rt",stdin);
     freopen("clocks.out","w",stdout);
    for(int i=0;i<9;i++)cin>>arr[i];
    go(8);
    bool f=true;
    for(int i=0;i<9;i++)
    {
            for(int j=1;j<=path[i];j++)
            {
                    if(f==true){ cout<<(i+1); f=false;}
                    else
                     cout<<" "<<(i+1);
            }
    }
    cout<<endl;    
}
