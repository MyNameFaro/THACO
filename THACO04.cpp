#include <bits/stdc++.h>
using namespace std;
using pii=pair<double,double>;
using tll=tuple<double,double,double>;

const int NN=30002;
const int MM=102;

bool inset(double x1,double y1,double x2,double y2,double r)
{
	double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return dis < r;
}
int main()
{
	int M,N;
	double x,y,r;
	double x1,x2,y1,y2;
	int ans=0;
	scanf("%d%d",&M,&N);
	vector <pii> G;
	priority_queue <tll,vector<tll>,greater<tll>> PQ;
	for(int i=1;i<=M;++i)
	{
		scanf("%lf%lf",&x,&y);
		G.emplace_back(x,y);
	}
	for(int i=1;i<=N;++i)
	{
		scanf("%lf%lf%lf",&x,&y,&r);
		PQ.emplace(r,x,y);
	}
	while(!PQ.empty())
	{
		r=get<0>(PQ.top());
		x2=get<1>(PQ.top());
		y2=get<2>(PQ.top());PQ.pop();
		int mem=0;
		for(int i=0;i<M;++i)
		{
			x1=G[i].first;
			y1=G[i].second;
			if(inset(x1,y1,x2,y2,r))
			{
				++mem;
			}
		}
		if(mem==M) break;
		if(mem) ++ans; 
	}
	printf("%d",ans);
}
