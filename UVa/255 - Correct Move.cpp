#include <iostream>
#include <string>
using namespace std;
string queenMove(int king, int queen, int newQ)
{
   int iKing=king/8, jKing=king%8, iQueen=queen/8, jQueen=queen%8, iNewQ=newQ/8, jNewQ=newQ%8;    
   if(iKing==iQueen&&jKing==jQueen)
    return "Illegal state";
   else if((iQueen!=iNewQ&&jQueen!=jNewQ)||(iNewQ==iQueen&&jNewQ==jQueen)||(jNewQ==jKing&&iKing==iNewQ)||(jKing==jNewQ&&jKing==jNewQ&&iQueen>iKing&&iNewQ<iKing)||(jKing==jNewQ&&jKing==jNewQ&&iQueen<iKing&&iNewQ>iKing)||(iKing==iNewQ&&iKing==iNewQ&&jQueen>jKing&&jNewQ<jKing)||(iKing==iNewQ&&iKing==iNewQ&&jQueen<jKing&&jNewQ>jKing))
    return "Illegal move";
   else if((jKing==jNewQ&&(iKing-iNewQ==1||iKing-iNewQ==-1))||(iKing==iNewQ&&(jKing-jNewQ==1||jKing-jNewQ==-1)))
    return "Move not allowed";  
   else if((iKing+1==8||(iKing+1==iNewQ))&&(iKing-1==-1||(iKing-1==iNewQ))&&(jKing+1==8||(jKing+1==jNewQ))&&(jKing-1==-1||(jKing-1==jNewQ))) 
    return "Stop";
   return "Continue";      
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  #endif   
  int king , queen, newQ;
  while(cin>>king>>queen>>newQ)
  {  
    cout<<queenMove(king, queen, newQ)<<endl; 
  }  
  return 0;    
}
