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

const int MAXN = 100005; // 1e5;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
LL tot;
priority_queue <P, vector<P>, greater<P> > que;
int cc[MAXN],ww[MAXN];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",cc+i);
	for (int i = 1; i <= n; i++) scanf("%d",ww+i);
	for (int i = 1; i <= n; i++)
	{
		int c = cc[i], w = ww[i];
		a[i] = c/100; b[i] = c%100;
		m-=b[i];
		if (b[i] > 0) que.push(P((100-b[i])*w,i));
		while(m < 0)
		{
			P t = que.top();
			m+=100, tot += t.fi;
			a[t.se]++, b[t.se] = 0;
			que.pop();
		}
	}
	printf("%lld\n",tot);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d\n",a[i],b[i]);
	}

}

