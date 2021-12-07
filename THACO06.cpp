#include <bits/stdc++.h>
using namespace std;

int P[100002];
bool visited[100002];
vector<int> ans;

int dfs(int fu)
{
	int u=fu ,uu;
	visited[u]=true;
	int ans=1;
	while(!visited[P[u]])
	{
		visited[P[u]]=true;
		u=P[u];
		++ans;
		
	}
	return ans;
}
int main()
{
	int N,Q;
	scanf("%d%d",&N,&Q);
	priority_queue <int> PQ; //for other worstcase
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&P[i]);
	}
	for(int i=1;i<=N;++i)
	{
		if(!visited[i])
		{
			PQ.push(dfs(i));
		}
	}
	while(!PQ.empty())
	{
		int cur=PQ.top();PQ.pop();
		if(cur==1) break;
		ans.push_back(cur);
		PQ.push(cur / 2);
		PQ.push((cur/2) + (cur%2));
	}
	while(Q--)
	{
		int k;
		scanf("%d",&k);
		if(k >= ans.size())
		{
			printf("1\n");
		}
		else{
			printf("%d\n",ans[k]);
		}
	}
}
