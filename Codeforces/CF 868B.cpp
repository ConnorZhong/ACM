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
int a[3];
int getpos(int t)
{
	if (t<=a[0]||t>a[2]) return 0;
	else if (t<=a[1] && t>a[0]) return 1;
	else return 2;
}
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>a[0]>>a[1]>>a[2]; a[1]/=5, a[2]/=5;
	int t1,t2;
	cin>>t1>>t2;
	sort(a,a+3);


	if (getpos(t1)==getpos(t2)) puts("YES");
	else puts("NO");
	return 0;
}

