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
#define pb push_back
#define mkp make_pair
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);i>=(a);i--)
#define de(x) cout<<">> "<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;
int n,m;
const int INF = 0x3f3f3f3f;
const int MAXN = 2000005; // 1e6;
const int maxn = 2000005;
namespace scc_cut_bridge{
	int n;
	vector <int> G[MAXN];
	stack <int> Tar; //说明： Tar 为记录未处理的回溯栈
	int dfn[MAXN], low[MAXN],idx=0,Bcnt=0;;//dfn[i] 第i个节点的dfs序，low[i] 第i个节点所能访问到的最早祖先(dfs序值)
	bool instack[MAXN];
	int belong [MAXN];
	//结果 Bcnt 表示强连通分量的数目
	void Tarjan(int u)
	{
	        dfn[u] = low[u] = ++idx;
	        instack[u] = true;
	        Tar.push(u);
	        for (int i=0;i<G[u].size();i++)
	        {
	                int v = G[u][i];
	          	if (!dfn[v])
	                {
	                        Tarjan(v);
	                        if (low[u] > low[v]) low[u] = low[v];
	                }
	                else if (instack[v] && low[u] > dfn[v]) low[u] = dfn[v];
	        }
	        if (dfn[u] == low[u]) {
	                Bcnt++;
	                while(!Tar.empty())
	                {
	                        int j = Tar.top();
	                        Tar.pop();
	                        instack[j] = false;
	                        belong[j]=Bcnt;
	                        if (j == u) break;
	                }
	        }
	}

	

	void solve()
	{
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(instack,0,sizeof instack);
		idx=0;
		while(!Tar.empty()) Tar.pop(); 
		for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i);
	}
} 
using namespace scc_cut_bridge;
vector<int> Array[MAXN];
int main()
{
	freopen("in.txt","r",stdin);
	string s;
	s += 'a';
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) 
	{
		int sz; scanf("%d",&sz);
		rep(j, 0, sz) 
		{
			int p;scanf("%d",&p);
			p--;
			Array[i].pb(p);

		}
	}
	rep(i,1,n)
	{
		int sz = min(Array[i].size(), Array[i+1].size());
		int flag = 0;

		rep(j,0,sz)
		{
			int u = Array[i][j], v = Array[i+1][j];
			if (u > v)
			{
				int u = Array[i][j], v = Array[i+1][j];
				G[u*2+1].pb(u*2); G[v*2].pb(v*2+1);
				flag = true;
				break;
			}
			else if (u < v)
			{
				G[v*2].pb(u*2);
				G[u*2+1].pb(v*2+1);
				flag = true;
				break;
			}
		}
		if (Array[i].size() > Array[i+1].size() && !flag)
		{
			return 0*puts("No");
		}
	}
	rep(i,0,(m<<1)) if (!dfn[i]) Tarjan(i);
	rep(i,0,m) if (belong[i*2]==belong[i*2+1]) return 0*printf("No\n");
	printf("Yes\n");
	vector<int> res;
	rep(i,0,m)
	{
		if (belong[i*2]<belong[i*2+1]) res.pb(i);
	}
	printf("%lu\n",res.size());
	rep(i,0,res.size())
	{
		printf("%d%c",res[i]+1," \n"[i==res.size()-1]);
	}

	return 0;
}

