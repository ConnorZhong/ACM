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
#include <cassert>
#include <bitset>
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
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
LL powmod(LL a,LL b,LL mod) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a, LL b) {if (b==0)return a;else return gcd(b,a%b);}
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005; // 1e6;
typedef pair<int, int > P;
vector<pair<int,int> > G[MAXN];
int d[MAXN];
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        rep(i, 1, N+1) G[i].clear();
        rep(i, 0, times.size())
        {
        	G[times[i][0]].pb(mkp(times[i][1],times[i][2]));
        	G[times[i][1]].pb(mkp(times[i][0],times[i][2]));

        }
        memset(d,INF,sizeof d);
	d[K]=0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(mkp(0,K));
	while(!que.empty())
	{
		int v=que.top().se;
		int x=que.top().fi;
		que.pop();
		if (x > d[K]) continue;
		rep(i,0,G[v].size())
		{
			int vv = G[v][i].fi, w = G[v][i].se;
			if (d[v] + w < d[vv])
			{
				d[vv]=d[v]+w;
				que.push(mkp(d[vv],vv));
			}

		} 
	}
	LL ans = 0;
	de(d[i])
	rep(i,1,N+1) ans = max(1ll*d[i],ans);
	if (ans==INF) ans = -1;
	return ans;
    }
};
int main()
{
	// freopen("in.txt","r",stdin);
	return 0;
}

