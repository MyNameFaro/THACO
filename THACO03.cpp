#include <bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;

int ans[505];
int main()
{
	int N,K;
	int l,r;
	scanf("%d%d",&N ,&K);
	vector <pair<int,int>> ls; //Line Sweep
	for(int i=1;i<=K;++i)
	{
		scanf("%d%d",&l,&r);
		ls.push_back({l , 1});
		ls.push_back({r+1 , 0});
	}
	sort(ls.begin() , ls.end());
	int cnt=0;
	vector <tll> slug;
	for(int i=0;i<ls.size();++i)
	{
		int t=ls[i].second;
		if(t)
		{
			++cnt;
		}
		else{
			slug.emplace_back(cnt , ls[i-1].first,ls[i].first);
			--cnt;
		}
	}
	sort(slug.begin() , slug.end());
	l=get<1>(slug[slug.size()-1]);
	r=get<2>(slug[slug.size()-1]);
	ans[l]=N;
	if(r-l>1)
	{
		ans[l+1]=1;
	}else{
		l=get<1>(slug[slug.size()-2]);
		ans[l]=1;
	}
	int j=2;
	for(int i=1;i<=N;++i)
	{
		if(ans[i]) continue;
		ans[i]=j;
		++j;
	}
	for(int i=1;i<=N;++i){
		printf("%d ",ans[i]);
	}
}
