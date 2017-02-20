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
typedef pair<int, int> P;
int n,m,k,f[MAXN];
P s[MAXN];
int ha[MAXN*10];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&f[i]);
		ha[f[i]]++;
	}
	for (int i = 1; i <= m; i++) scanf("%d",&s[i].fi),s[i].se = i;
	sort(s+1,s+1+m);
	int cnt = 0, now = 0;
	for (int i = MAXN*10-1;i >= 0; i--)
	{
		if (ha[i] > k) now += ha[i] - k, ha[i] = k;
		else 
		{
			int tmp = min(k-ha[i],now);
			now -= tmp, ha[i] += tmp;
		}
	}
	stack<int> ans;
	if (now > 0) return 0*printf("-1\n");
	now = 0;
	for (int i = 1; i <= m; i++)
	{
		while (k - ha[now] <= 0 && s[i].fi >= now)
		{
			// cout<<"now "<<now<<" "<<i<<endl;
			now ++;
		}
		if (k - ha[now] > 0 && s[i].fi >= now) 
		{
			
			ans.push(s[i].se);
			// cout<<i<<" "<<s[i].fi<<" "<<s[i].se<<endl;
			ha[now]++;
			// cout<<ha[now]<<" "<<now<<" "<<i<<endl;
			cnt++;
		}
	}
	printf("%d\n",cnt );
	while(!ans.empty()) printf("%d ", ans.top()), ans.pop();

}

