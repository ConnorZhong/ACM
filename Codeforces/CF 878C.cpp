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

const int INF = 0x3f3f3f3f;
const int MAXN = 100005; // 1e6;
int n,k,a[20];
int low[MAXN][20], up[MAXN][20], sz[MAXN];
set<pair<int,int> > U[20],L[20];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i, 1, n+1)
	{
		rep(j, 1, k+1) scanf("%d",a+j);
		int pid = 1e9+1, qid = -1; sz[i] = 1;
		set<pair<int,int> > :: iterator p, q;
		rep(j, 1, k+1)
		{
			p = L[j].lower_bound(mkp(a[j],0)); // 上界
			if (p!=L[j].begin()) qid = max(qid, low[(--p)->se][1]);
			q = U[j].lower_bound(mkp(a[j],0)); // 下届
			if (q!=U[j].end()) pid = min(pid, low[(q)->se][1]);
		}
		rep(j, 1, k+1) low[i][j]=up[i][j]=a[j];
		while(pid <= qid)
		{
			// de(pid) de(qid)
			p = L[1].lower_bound(mkp(pid, 0));
			if (p == L[1].end() || p->fi > qid) break;
			int id = p->se;
			pid = low[id][1];
			// de(pid)
			sz[i] += sz[id];
			rep(j, 1, k+1)
			{
				L[j].erase(mkp(low[id][j], id));
				U[j].erase(mkp(up[id][j], id));
				low[i][j] = min(low[id][j],low[i][j]);
				up[i][j] = max(up[id][j],up[i][j]);
			}

		}
		rep(j, 1, k+1) L[j].insert(mkp(low[i][j],i)), U[j].insert(mkp(up[i][j],i));
		printf("%d\n",sz[(--L[1].end())->se]);
	}
	return 0;
}

