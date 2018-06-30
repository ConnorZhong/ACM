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
string str;
int cnt = 0;
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>str;
	int pos = -1;
	pos=-1;while((pos = str.find("Danil",pos+1))!=string::npos) cnt++;
	pos=-1;while((pos = str.find("Olya",pos+1))!=string::npos) cnt++;
	pos=-1;while((pos = str.find("Slava",pos+1))!=string::npos) cnt++;
	pos=-1;while((pos = str.find("Ann",pos+1))!=string::npos) cnt++;
	pos=-1;while((pos = str.find("Nikita",pos+1))!=string::npos) cnt++;
	// de(cnt)
	// de(str.length())
	// de(str.find("And",5));
	if (cnt == 1) puts("YES");
	else puts("NO");
	return 0;
}

