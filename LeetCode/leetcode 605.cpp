class Solution {
public:
bool canPlaceFlowers(vector<int>& f, int n) {
for (int i=0;i<(int)f.size();i ++) {
    if (f[i]==1) continue;
	if (i > 0 && f[i-1] == 1) continue;
            if (i<(int)(f.size()-1) && f[i+1]==1) continue;
           n--;f[i]=1;
}
return n <= 0;
}        
   };

