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
const int MAXN = 1<<18; // 1e6;
bool STree[MAXN], Lazy[MAXN];
int s1,s2, x[MAXN], ii[MAXN];
int xx[MAXN], nn,n;
void push_down(int k)
{
	if (Lazy[k])
	{
		Lazy[k]=0;
		Lazy[k<<1]=1;
		Lazy[k<<1|1]=1;
		STree[k<<1]=0;
		STree[k<<1|1]=0;
	}
}
void push_up(int k)
{
	STree[k]=max(STree[k<<1],STree[k<<1|1]);
}
void modify(int k, int l, int r, int ql, int qr, int x)
{
	if (ql >= r || qr <= l) return;
	if (ql <= l && r <= qr) 
	{
		STree[k]=x;
		Lazy[k]=1;
		return;
	}
	int m=(l+r)>>1;
	push_down(k);
	modify(k<<1,l,m,ql,qr,x);
	modify(k<<1|1,m,r,ql,qr,x);
	push_up(k);
}
bool query(int k, int l, int r, int ql, int qr)
{
	if (ql >= r || qr <= l) return 0;
	if (ql <= l && r <= qr)
	{
		return STree[k];
	}
	int m=(l+r)>>1;
	push_down(k);
	bool ret = max(query(k<<1,l,m,ql,qr),query(k<<1|1,m,r,ql,qr));
	push_up(k);
	return ret;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&s1,&s2);
	if (s1 > s2) swap(s1,s2);

	int l=s2-s1-1, r=1e9+1;

	rep(i,1,n+1) scanf("%d",x+i);
	xx[nn++]=s1;xx[nn++]=s2;
	rep(i,1,n+1) xx[nn++]=x[i];
	sort(xx,xx+nn);
	rep(i,1,n+1) x[i]=lower_bound(xx,xx+nn,x[i])-xx;
	s1 = lower_bound(xx,xx+nn,s1)-xx;
	s2 = lower_bound(xx,xx+nn,s2)-xx;	
	while (r-l > 1)
	{
		int m=(l+r)>>1;

		memset(STree,0,sizeof STree);
		memset(Lazy,0,sizeof Lazy);

		modify(1,0,nn,s1,s1+1,1);
		modify(1,0,nn,s2,s2+1,1);
		bool flag = true;
		rep(i,1,n+1)
		{
			int nowx = xx[x[i]];
			int nowl = lower_bound(xx,xx+nn,nowx-m)-xx;
			int nowr = upper_bound(xx,xx+nn,nowx+m)-xx;
			if (query(1,0,nn,nowl,nowr))
			{
				modify(1,0,nn,x[i],x[i]+1,1);
				modify(1,0,nn,0,nowl,0);
				modify(1,0,nn,nowr,nn,0);
			}
			else 
			{
				flag = false;
				break;
			}
		}
		if (flag) r = m;
		else l = m;
	}
	printf("%d\n",r);
	return 0;
}

