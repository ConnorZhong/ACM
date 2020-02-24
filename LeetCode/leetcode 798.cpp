class Solution {
public:

    int bestRotation(vector<int>& A) {
        int d[40005];memset(d,0,sizeof d);
        int bias = 20002;
        int n = A.size();
        int maxx = -1, idx = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) d[A[i]-i+bias]++;
        for (int i = 0; i <= bias; i++) 
        {
            cnt += d[i];
        } 
        if (cnt > maxx) maxx=cnt,idx=0;
        for (int i = 1; i < n; i++)
        {
            cnt -= d[bias-i+1];
            d[A[i-1]-(i-1)+bias]--;
            d[A[i-1]-(i-1)+bias-(n)]++;
            cnt++;
            if (cnt > maxx) maxx=cnt,idx=i;
        }
        return idx;

    }
};