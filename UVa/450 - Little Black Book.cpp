#include <iostream>
#include <vector>
#include <string>
using namespace std;
void trim(string &str)
{
   while(str[0]==' ')
    str.erase(0,1);
   while(str[str.size()-1]==' ')
    str.erase(str.size()-1,1);
   for(int i=0;i<str.size();i++)
   {
      if(str[i]==' '&&i>1&&i<str.size()-1)
       if(str[i-1]==' '||str[i+1]==' ')
       {
         str.erase(i,1);
         i--;
       }         
   }       
}
vector <string> extractD(string spare, string dept)
{     
  vector <string> res; // result
  string help;
  int counter=0;
  for(int i=0;i<spare.size();i++)
  {
     if(spare[i]==',')
     {
        trim(help);              
        res.push_back(help);
        counter++;
        if(counter==4)
         res.push_back(dept);
        help.clear();                 
     }
     /*else if(spare[i]==' ')
      continue;*/
     else 
      help+=spare[i];                    
  } 
 trim(help);   
 res.push_back(help);
 return res;      
}
void sortData (vector < vector <string> > &fData)
{
   int size=fData.size();
   int pos;  
   while(size)
   {            
    for(int i=1;i<fData.size();i++)
    {
     pos=0; 
     while(fData[i][2][pos]==fData[i-1][2][pos])
      pos++;      
     if(fData[i][2][pos]<fData[i-1][2][pos])
       swap(fData[i],fData[i-1]);  
    }
    size--;
   }  
}
int main()
{
     
   int nDept;
   string dept,spare,dummy;
   vector < vector <string> > fData; // full data
   vector <string> sData; // single data
   cin>>nDept;
   getline(cin,dummy);
   for(int i=0;i<nDept;i++)
   {
     getline(cin,dept);
     while(getline(cin,spare)&&!spare.empty())
     {
       sData=extractD(spare,dept);
       fData.push_back(sData);                                                                               
     }            
   } 
   sortData(fData);
   for(int i=0;i<fData.size();i++)
   {
     cout<<"----------------------------------------\n";
     for(int j=0;j<fData[i].size();j++)
     {
         if(j<2)
          cout<<fData[i][j]<<" ";
         else if(j<4)
          cout<<fData[i][j]<<endl;
         else if(j==4)
          cout<<"Department: "<<fData[i][j]<<endl;
         else if(j==5)
          cout<<"Home Phone: "<<fData[i][j]<<endl;
         else if(j==6)
          cout<<"Work Phone: "<<fData[i][j]<<endl;
         else if(j==7)
          cout<<"Campus Box: "<<fData[i][j]<<endl;      
     }              
   }  
   system("pause");
   return 0;  
}
