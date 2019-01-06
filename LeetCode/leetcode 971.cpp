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

// int main()
// {
//         freopen("in.txt","r",stdin);
//         return 0;
// }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool flag = true;
int dfs(TreeNode* u, int i, vector<int> &voyage, vector<int>& ans)
{
        if (u == NULL) return i-1;
        if (u->val != voyage[i]) 
        {
                flag=false;return i;
        }
        if (u->left==NULL);
        else if (u->left->val != voyage[i+1]) 
        {
            ans.pb(u->val);
            swap(u->left, u->right);
        }
        i = dfs(u->left, i+1, voyage, ans);
        i = dfs(u->right, i+1, voyage, ans); 
        return i;
}
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        flag=true;
        int len = voyage.size();
        dfs(root, 0, voyage, ans);
        if (flag) return ans;
        else 
        {
                ans.clear();
                ans.pb(-1);
                return ans;
        }
    }
};