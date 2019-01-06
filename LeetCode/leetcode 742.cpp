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
const int MAXN = 1200; // 1e6;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> G[MAXN];
bool isleaf[1200];
int d[MAXN];
void build(TreeNode *root)
{
	if (root->right != NULL) 
	{
		G[root->val].pb((root->right)->val);
		G[(root->right)->val].pb(root->val);
		build(root->right);
	}
	if (root->left != NULL)
	{
		G[root->val].pb(root->left->val);
		G[root->left->val].pb(root->val);
		build(root->left);		
	}
	if (root->right == root->left && root->right == NULL && root->left==NULL) 
	{
        de(root->val)
		isleaf[root->val] = true;
	}
}

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
      	rep(i,0,MAXN) G[i].clear();
      	memset(isleaf,0,sizeof isleaf);
        memset(d,-1,sizeof d);
      	build(root);
      	queue<int> que;
      	d[k]=0;que.push(k);
        de(k)
      	while(!que.empty())
      	{
      		int x=que.front();
      		que.pop();
            de(x)
      		if (isleaf[x]==true) return x;
      		rep(i,0,G[x].size())
      		{
      			int v=G[x][i];
                de(v)
      			if (d[v] == -1) 
      			{
      				d[v]=d[x]+1;
      				que.push(v);
      			}
      		}
      	}
    }
};


