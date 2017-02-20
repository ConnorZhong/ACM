#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

const int MAXN = 1000005; // 1e5;
int n,a[MAXN];
std::vector<int> G[MAXN];
int dp[MAXN];
int ans[3], cnt = 0;
int tot,s;
void dfs(int i, int fa)
{
	dp[i] = a[i];
	for (int j = 0; j < G[i].size(); j++)
	{
		int v=G[i][j];
		if (v==fa)continue;
		dfs(v,i);
		dp[i]+=dp[v];
	}
	if (dp[i] == tot/3) dp[i] = 0, ans[cnt++] = i;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d%d",&t,&a[i]);
		if (t!=0) 
		{
			G[t].push_back(i);
			G[i].push_back(t);
		}
		else s = i;
	}
	for (int i = 1; i <= n; i++) tot+=a[i];
	if (tot %3 != 0) return 0*printf("%d\n",-1);
	dfs(s,-1);
	if (cnt >= 3˜) 
	printf("%d %d\n",ans[0],ans[1] );
	else 
		printf("-1\n");

}

