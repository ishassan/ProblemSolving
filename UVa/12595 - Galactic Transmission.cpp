#include<bits/stdtr1c++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pr;
vector<pr> v,vq;
struct point
{
    LL x,y,z;
    point(LL a,LL b,LL c)
    :x(a),y(b),z(c){}
    point(){}
};
LL Dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+
           (a.y-b.y)*(a.y-b.y)+
           (a.z-b.z)*(a.z-b.z);
}
int n;
map<LL,LL> mx,my;
struct event
{
    LL x,y;
    bool p;
    int ind;
    event(){};
    event(LL x,LL y,bool p,int ind=0)
    :x(x),y(y),p(p),ind(ind){}
};
bool cmp(const event &a,const event &b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.p>b.p;
}
bool cmp2(const event &a,const event &b)
{
    if(a.y!=b.y)
        return a.y<b.y;
    return a.p>b.p;
}
vector<event> E;
vector<LL> x,y,ans;

int MAXI=500000*2 + 100;
int bit[500000*2 + 100];

void update(int x)
{
    while(x<MAXI)
    {
        bit[x]++;
        x+=(x&-x);
    }
}
int query(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=bit[x];
        x-=(x&-x);
    }
    return ret;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("2.in","r",stdin);

    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    LL a,b,c;
    cin>>a>>b>>c;
    point p1=point(a,b,c);
    cin>>a>>b>>c;
    point p2=point(a,b,c);

    for(int i=2;i<n;i++)
    {
        cin>>a>>b>>c;
        LL X=Dist(point(a,b,c),p1);
        LL Y=Dist(point(a,b,c),p2);
        //cout<<X<<" "<<Y<<endl;
        v.push_back(pr(X,Y));
        if(mx.count(X)==0)
        {
            mx[X]=1;
            x.push_back(X);
        }

        if(my.count(Y)==0)
        {
            my[Y]=1;
            y.push_back(Y);
        }
    }
    int q;
    cin>>q;
    ans.resize(q);
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        LL X=a*a;
        LL Y=b*b;
         if(mx.count(X)==0)
        {
            mx[X]=1;
            x.push_back(X);
        }

        if(my.count(Y)==0)
        {
            my[Y]=1;
            y.push_back(Y);
        }
        vq.push_back(pr(X,Y));
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=0;i<x.size();i++)
        mx[x[i]]=i+1;
    for(int i=0;i<y.size();i++)
        my[y[i]]=i+1;

    for(int i=0;i<v.size();i++)
    {
        E.push_back(event(mx[v[i].first],my[v[i].second],1,0));
    }
    for(int i=0;i<vq.size();i++)
    {
        E.push_back(event(mx[vq[i].first],my[vq[i].second],0,i));
    }
    sort(E.begin(),E.end(),cmp);

    for(int i=0;i<E.size();i++)
    {

        if(E[i].p)
            update(E[i].y);
        else
            ans[E[i].ind]-=query(E[i].y);
    }
     c=0;
    for(int i=0;i<E.size();i++)
    {
        if(E[i].p)
            c++;
        else
            ans[E[i].ind]+=c;
    }
    sort(E.begin(),E.end(),cmp2);
    c=0;
    for(int i=0;i<E.size();i++)
    {
        if(E[i].p)
            c++;
        else
            ans[E[i].ind]+=c;
    }


    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;


    return 0;

}
