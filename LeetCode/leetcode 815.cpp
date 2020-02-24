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


class Solution {
public:
    vector<int> R[1000000];
    int vis[600],que[1000000],d[1000000];
    int numBusesToDestination(vector<vector<int>>& G, int S, int T) {
        int n = G.size();
        for (int i=0;i<1000000;i++) R[i].clear();
        for (int i=0;i<n;i++) for (int j=0;j<G[i].size();j++) R[G[i][j]].push_back(i);
        memset(d,0x3f,sizeof d);
        memset(vis,0,sizeof vis);
        int q = 0, qq = 0;
        que[qq++]=S;d[S]=0;
        // cout<<1<<endl;
        de(S)
        for (;q<qq;q++)
        {
            int x = que[q];
            // de(x)
            for (int i=0;i<R[x].size();i++)
            {
                int y=R[x][i];
                
                if (!vis[y])
                {
                    vis[y]=1;
                    de(y)
                    for (int j=0;j<G[y].size();j++) 
                    {

                        int v = G[y][j]; if (d[v] > d[x]+1) d[v]=d[x]+1, que[qq++]=v;
                        de(v)
                    }
                }
            }
        }
        de(d[T])
        if (d[T]<100000)
        return d[T];
        else return -1;
        
    }
};

Solution s;
int main()
{
	
	vector<vector<int> > p;
	p.resize(2);
	rep(i,0,2)
	{
		p[i].resize(3);
	} 
	p[0][0]=1;
	p[0][1]=2;
	p[0][2]=7;
	p[1][0]=3;
	p[1][1]=6;
	p[1][2]=7;
	s.numBusesToDestination(p,1,6);
	// de(s.numBusesToDestination(p,1,6));
	return 0;
}
