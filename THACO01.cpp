#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	pii DP[N+1][M+1];
	pii P[N+1][M+1];
	char s[N+1][M+1];
	for(int i=0;i<=N;++i) DP[i][0]=make_pair(0,0);
	for(int j=0;j<=M;++j) DP[0][j]=make_pair(0,0);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			cin >> s[i][j];
		}
	}
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			
			if(s[i][j] == 'R')
			{
				if(min(DP[i-1][j].second , DP[i-1][j].first + 1) > min(DP[i][j-1].second , DP[i][j-1].first + 1) or j==1)
				{
					DP[i][j]=make_pair(DP[i-1][j].first + 1 , DP[i-1][j].second);
					P[i][j] = make_pair(i-1,j);
				}else{
					DP[i][j]=make_pair(DP[i][j-1].first + 1 , DP[i][j-1].second);
					P[i][j] = make_pair(i,j-1);
				}
			}
			else{
				if(min(DP[i-1][j].second + 1 , DP[i-1][j].first) > min(DP[i][j-1].second + 1 , DP[i][j-1].first) or j==1)
				{
					DP[i][j]=make_pair(DP[i-1][j].first , DP[i-1][j].second + 1);
					P[i][j] = make_pair(i-1,j);
				}else{
					DP[i][j]=make_pair(DP[i][j-1].first , DP[i][j-1].second + 1);
					P[i][j] = make_pair(i,j-1);
				}
			}
			
		}
		
	}
	P[1][1]=make_pair(-1,-1);
	int color = min(DP[N][M].second,DP[N][M].first);
	printf("%d\n",color*2);
	
	stack <pii> S;
	int i=N,j=M;
	while(i>0 and j>0)
	{
		S.push({i,j});
		int ii=P[i][j].first;
		int jj=P[i][j].second;
		i=ii;
		j=jj;
	}
	i=0;j=0;
	int cnt_R=0,cnt_G=0;
	while(!S.empty()){
		int ii=S.top().first;
		int jj=S.top().second;S.pop();
		//cout << ii << " " << jj << endl;
		if(!(ii==1 and jj==1))
		{
			if(abs(ii-i))
			{
				printf("D\n");
			}else{
				printf("R\n");
			}
		}
		if(s[ii][jj]=='R')
		{
			if(cnt_R<color)
			{
				++cnt_R;
				printf("Y ");
			}else{
				printf("N ");
			}
		}
		else{
			if(cnt_G<color)
			{
				++cnt_G;
				printf("Y ");
			}else{
				printf("N ");
			}
		}
		
		i=ii;
		j=jj;
	}
}
