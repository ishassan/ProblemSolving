/*
ID: b2lawa1
PROG: packrec
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define h first
#define w second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y) 
vector <pair <int,int> > req(4);
vector <int> prm(4);
vector <pair < int,pair <int ,int> > > area;
int high,width;
bool f [100][100]={0};
void test1 ()
{
     width=0;
     high=0;
     for(int i=0;i<prm.size();i++) width+=req[prm[i]].w;
     high= max(req[prm[0]].h, max(req[prm[1]].h,max(req[prm[2]].h,req[prm[3]].h)));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else  f[width][high]=1,area.pb(mp(high*width,mp(width,high)));
}
void test2 ()
{
     width=0;
     high=0;
     width= max( (req[prm[0]].w+req[prm[1]].w+req[prm[2]].w), req[prm[3]].w);
     high= req[prm[3]].h +max(req[prm[0]].h,max(req[prm[1]].h,req[prm[2]].h));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else f[width][high]=1, area.pb(mp(high*width,mp(width,high)));
}
void test3()
{
     width=0;
     high=0;
     width=req[prm[2]].w  + max(req[prm[3]].w,(req[prm[0]].w+req[prm[1]].w));
     high=max(req[prm[2]].h , (req[prm[3]].h+max(req[prm[0]].h,req[prm[1]].h)));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else  f[width][high]=1,area.pb(mp(high*width,mp(width,high)));
}
void test4()
{
     width=0;
     high=0;
     width=req[prm[3]].w+req[prm[0]].w +max(req[prm[1]].w,req[prm[2]].w);
     high = max( req[prm[3]].h,max(req[prm[0]].h ,(req[prm[1]].h+req[prm[2]].h)));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else  f[width][high]=1,area.pb(mp(high*width,mp(width,high)));
}
void test5()
{
     width=0;
     high=0;
     width=req[prm[3]].w+req[prm[2]].w +max(req[prm[1]].w,req[prm[0]].w);
     high = max( req[prm[3]].h,max(req[prm[2]].h ,(req[prm[1]].h+req[prm[0]].h)));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else  f[width][high]=1,area.pb(mp(high*width,mp(width,high)));
}
void test6()
{
     width=0;
     high=0;
     
     high=max((req[prm[0]].h+req[prm[1]].h),(req[prm[3]].h+req[prm[2]].h));
     if(req[prm[1]].h <= req[prm[3]].h) 
     width=max((req[prm[0]].w+req[prm[2]].w),max((req[prm[3]].w+req[prm[1]].w),(req[prm[3]].w+req[prm[0]].w)));
     else 
     width=max((req[prm[0]].w+req[prm[2]].w),max((req[prm[3]].w+req[prm[1]].w),(req[prm[2]].w+req[prm[1]].w)));
     if(high<width) f[high][width]=1,area.pb(mp(high*width,mp(high,width)));
     else f[width][high]=1, area.pb(mp(high*width,mp(width,high)));
}
void go(int i)
{
     if(i==4)
     {
             
             test1();
             test2();
             test3();
             test4();
             test5();
             test6();
             return ;
     }
     go(i+1);
     swap(req[i].h,req[i].w);
     go(i+1);
}     
int main()
{
    //freopen("in.txt","rt",stdin);
    //freopen("out.txt","w",stdout);
    freopen("packrec.in","rt",stdin);
    freopen("packrec.out","w",stdout);
    for(int i=0;i<req.size();i++)
    {
            cin>>req[i].h>>req[i].w;
            prm[i]=i;
    }
    do
    {
            go(0);
    }while(next_permutation(prm.begin(),prm.end()));
    sort(area.begin(),area.end());
    int res=area[0].first;
    cout<<res<<endl;
    cout<<area[0].second.h<<" "<<area[0].second.w<<endl;
    f[area[0].second.h][area[0].second.w]=0;
    for(int i=1 ; i<area.size();i++)
    {
            if(area[i].first !=res)break;
            if( f[area[i].second.h][area[i].second.w])
            cout<<area[i].second.h<<" "<<area[i].second.w<<endl,f[area[i].second.h][area[i].second.w]=0;
    }
    
}


