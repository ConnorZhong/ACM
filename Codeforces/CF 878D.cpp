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
bitset<4096> q[MAXN];
vector<pair<int,int> > v[MAXN];
int n,k,Q,id;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&Q);
	rep(i, 1, k+1)
	{
		rep(j, 1, n+1) 
		{
			int p;scanf("%d",&p);v[j].pb(mkp(p,i));
		}
		rep(j, 0, 4096) q[i][j]=j>>(i-1)&1;
	}
	id = k;

	rep(i, 1, n+1) sort(v[i].begin(),v[i].end());
	rep(i ,1, Q+1)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		// de(op) de(x) de(y)
		if (op == 1) q[++id] = q[x]|q[y];
		if (op == 2) q[++id] = q[x]&q[y];
		if (op == 3)
		{
			// de(k)
			int w = 0;
			per(j, 0, k)
			{
				// de(w) de(v[y][j].se) de(v[y][j].fi)
				w |= 1<<(v[y][j].se - 1);
				// de(w)
				if (q[x][w])
				{
					printf("%d\n",v[y][j].fi);
					break;
				}
			}
		}
	}
	return 0;
}

