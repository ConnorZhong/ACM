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
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);b>=(a);i--)
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

const int MAXN = 200005; // 2e5;
int n,m,k,t;
vector<int> G[MAXN];
vector<int> Path[MAXN];
bool visited[MAXN];
int cnt = 1;
void upd(int x)
{
	if (Path[cnt].size() >= t) cnt++;
	Path[cnt].push_back(x);
	// cout<<1<<endl;
}
void dfs(int i)
{
	visited[i] = true;
	// cout<<i<<endl;
	for (int j = 0; j < G[i].size(); j++)
	{
		int v = G[i][j];
		// cout<<v<<endl;
		if (visited[v]) continue;
		upd(v);
		dfs(v);
		upd(i);
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		G[t].push_back(s);
	}
	t = (n*2+(k-1))/k;
	// cout<<t<<endl;
	upd(1);
	dfs(1);
	// cout<<cnt<<endl;
	rep(i,1,k+1)
	{
		if (Path[i].size()!=0)
		{
			printf("%d ",Path[i].size());
			for(auto &x: Path[i]) printf("%d ",x);
		}
		else 
			printf("1 1");
		printf("\n");
	}

}

