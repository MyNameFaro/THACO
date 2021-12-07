#include <bits/stdc++.h>
using namespace std;
int R,C;
int memo[52][52][52][52];

long long int walk(int r1,int c1,int r2,int c2){
	if(memo[r1][c1][r2][c2] == 0){
		if(r1 == R && r2 == R && c2 == C && c1 == C){
			memo[r1][c1][r2][c2] = 1;
		}else{
			memo[r1][c1][r2][c2] = 0;
			if(r1 != R && r2 != R && r1 != r2){
				memo[r1][c1][r2][c2] += walk(r1 + 1,c1,r2 + 1,c2);
			}
			if(c1 != C && c2 != C && c1 != c2 ){
				memo[r1][c1][r2][c2] += walk(r1,c1 + 1,r2 ,c2 + 1);
			}
			if(c1 != C && r2 != R && c1 != c2 && r2 != r1){
				memo[r1][c1][r2][c2] += walk(r1,c1 + 1,r2 + 1,c2);
			}
			if(c2 != C && r1 != R && c2 != c1 && r1 != r2){
				memo[r1][c1][r2][c2] += walk(r1 + 1,c1,r2,c2 + 1);
			}
		}
	}
	return memo[r1][c1][r2][c2];
}

int main(){
	scanf("%d%d",&R,&C);
	cout << walk(1 , 1 ,1 ,1);
}
