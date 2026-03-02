class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int n = nums.size();
        const int* A = nums.data();
        
        static long long pre[100002];
        static int stk[100002];
        
        pre[0] = 0;
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + A[i];
        
        stk[0] = -1;
        int top = 0;
        long long ans = 0;
        
        for (int r = 0; r <= n; ++r) {
            int cur = (r < n) ? A[r] : 0;
            
            while (top > 0 && A[stk[top]] > cur) {
                int i = stk[top--];
                int l = stk[top];
                
                long long sum = pre[r] - pre[l + 1];
                long long product = (long long)A[i] * sum;
                
                ans = max(ans, product);
            }
            
            stk[++top] = r;
        }
        
        return ans % (int)(1e9 + 7);
    }
};