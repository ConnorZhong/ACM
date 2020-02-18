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
vector<int> G[MAXN];
int n,m,k,d[MAXN],q[MAXN];
int idx[MAXN];
int s[MAXN];
int sufmaxd[MAXN];
bool cmp(int i, int j){
        return d[i]-q[i]<d[j]-q[j];
}
int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%d%d%d",&n,&m,&k);
        rep(i, 0, k){
                scanf("%d",s+i);
        }
        rep(i, 1, n+1) idx[i]=i;
        rep(i, 0, m) {
                int u,v;scanf("%d%d",&u,&v);
                G[u].pb(v);G[v].pb(u);
        }
        memset(d, INF, sizeof d);
        memset(q, INF, sizeof q);
        queue<pair<int,int> >que;
        d[1]=0;que.push(mkp(1, 0));
        while(!que.empty())
        {
                int u = que.front().first;
                int x = que.front().second;
                que.pop();
                if (d[u]!=x) continue;
                rep(i, 0, G[u].size()){
                        int v=G[u][i];
                        if (d[v]>x+1) 
                        {
                                d[v]=x+1;
                                que.push(mkp(v,d[v]));
                        }
                }

        }
        q[n]=0; que.push(mkp(n,0));
        while(!que.empty())
        {
                int u = que.front().first;
                int x = que.front().second;
                que.pop();
                if (q[u]!=x) continue;
                rep(i, 0, G[u].size()){
                        int v=G[u][i];
                        if (q[v]>x+1) 
                        {
                                q[v]=x+1;
                                que.push(mkp(v,q[v]));
                        }
                }

        }
        sort(s,s+k, cmp);
        sufmaxd[s[k-1]] = q[s[k-1]]; 
        per(i,0,k-1) sufmaxd[s[i]]=max(sufmaxd[s[i+1]],q[s[i]]);
        int tt = 0;
        rep(i, 0, k-1) tt = max(d[s[i]]+sufmaxd[s[i+1]]+1, tt);
        tt = min(tt, d[n]);
        printf("%d\n",tt);
        return 0;
}

