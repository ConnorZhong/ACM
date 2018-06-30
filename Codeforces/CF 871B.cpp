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
const int MAXN = 1000005; // 1e6;
int sum = 0, n;
vector<int> vec;
int perm[MAXN],p[MAXN];
bool check(int i)
{
	int total=0;
	rep(j, 0, n)
	{
		total+=i^j;
	}
	if (total != sum) return 0;
	if (p[i] == i) return 1;
	return 0;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",p+i);
		sum += p[i];
	} 
	rep(i, 0, n) if (check(i)) vec.pb(i);
	perm[vec[0]]=0;
	rep(i, 0, n)
	{

		int x;
		printf("? %d %d\n",vec[0], i);
		fflush(stdout);
		scanf("%d",&x);
		// if (x >= n) 1/0;
		perm[x]=i;
	}
	printf("!\n%lu\n",vec.size());
	rep(i, 0, n) printf("%d%c",perm[i]," \n"[i==n-1]);
	fflush(stdout);
	return 0;
}

