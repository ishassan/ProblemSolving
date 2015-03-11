/*
ID: xp4frav
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("clocks.out");
	ifstream fin ("clocks.in");
	
	int i, k, j, num, value, size = 262144;
	
	int move[9], mainClock[9];
	char *p;

	char *place[9] = 
{"013" , "0124", "125","0346","02468" ,"2458", "367" , "4678","578" }; 
//	In this strange array e.g 013 is the places where a is found
	
    for(i=0; i<9; i++)
		fin>>mainClock[i];
	
	for(i=0;i<size;i++)
	{
		num = i;
		for(j=0;j<9;j++)
		{
			move[j] = num%4;
			num/=4;	
		}	//Get the 4th system representaion in number system
		
		for(k=0; k<9; k++)
		{	//checking every place one by one
			value = mainClock[k];
			for(p=place[k]; *p; p++)
				value+= (3 * move[*p-'0']);
			if(value%12)
				break;
		}
		if(k<9)
			continue;
		break;
	}
	
	
	p =""; 
	for(i=0; i<9; i++) 
		for(j=0; j<move[i]; j++) 
		{
			fout<< p << i+1;
			p = " ";
		}
		fout<<"\n";

		return 0;
}
