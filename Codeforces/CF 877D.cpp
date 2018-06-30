#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cstdlib>
// #include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);i>=(a);i--)
#define de(x) cout<<">> "<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;
const int MAXN = 1111; // 1e6;
int dp[MAXN][MAXN],n,m,k,x1,x2,y1,y2;
char fld[MAXN][MAXN];
bool vis[MAXN][MAXN][4];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
priority_queue<pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >,greater< pair<int, pair<int,int> > > > Q;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) scanf("%s",fld[i]+1);
	memset(dp,INF,sizeof dp);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	dp[x1][y1]=0;
	// rep(i,0,4) vis[x1][y1][i]=1;
	Q.push(mkp(0,mkp(x1,y1)));
	while(!Q.empty())
	{
		int x = Q.top().se.fi, y = Q.top().se.se;

		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x, ty = y;
			for (int s = 0; tx >= 1 && tx <= n && ty >= 1 && ty <= m && fld[tx][ty]=='.'; s++, tx += dx[i], ty += dy[i])
			{
				if (vis[tx][ty][i]) break;
				vis[tx][ty][i]=true;
				if (dp[tx][ty] > dp[x][y] + (s-1)/k + 1){
					dp[tx][ty] = min(dp[tx][ty], dp[x][y] + (s-1)/k + 1);
					Q.push(mkp(dp[tx][ty], mkp(tx,ty)));
				}
			}
		}
	}
	if (dp[x2][y2]==INF) puts("-1");
	else printf("%d\n",dp[x2][y2]);
	return 0;
}

