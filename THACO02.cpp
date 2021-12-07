#include <bits/stdc++.h>
using namespace std;
int DP[102][102][102][102];
const int mod=1e9+7;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	DP[1][1][1][1]=1;
	for(int r1=1;r1<=N;++r1)
	{
		for(int r2=1;r2<=N;++r2)
		{
			for(int c1=1;c1<=M;++c1)
			{
				for(int c2=1;c2<=M;++c2)
				{
					if(r1==1 and c1==1 and r2==1 and c2==1) continue;
					if((r1 == r2 or c1 == c2) and !(r1==r2 and c1==c2)) continue;
					int ans=0;
					if(r1-1 != r2-1) ans+=DP[r1-1][c1][r2-1][c2];
					ans%=mod;
					ans+=DP[r1][c1-1][r2-1][c2];
					ans%=mod;
					ans+=DP[r1-1][c1][r2][c2-1];
					ans%=mod;
					if(c1-1 != c2-1) ans+=DP[r1][c1-1][r2][c2-1];
					ans%=mod;
					DP[r1][c1][r2][c2]=ans;
				}
			}		
		}
	}
	printf("%d",DP[N][M][N][M]);
}
