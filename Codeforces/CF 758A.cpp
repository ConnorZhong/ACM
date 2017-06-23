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

const int inf = 0x3f3f3f3f;

const int maxn = 1000010*2;
int n;
int a[maxn], money, mx;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
		money += a[i];
		mx = max(mx,a[i]);
	}
	cout<<mx*n - money<<endl;



}

