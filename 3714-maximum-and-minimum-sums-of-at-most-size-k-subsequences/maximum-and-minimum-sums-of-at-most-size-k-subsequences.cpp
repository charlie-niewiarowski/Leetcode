const long long MOD = 1e9 + 7;

class Comb {
private:
    vector<long long> fact;
    vector<long long> invfact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    Comb(int n) {
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invfact[n] = modPow(fact[n], MOD - 2);  

        for (int i = n - 1; i >= 0; i--)
            invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }
};

class Solution {
private:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    int comb(int n, int k) {
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0, num_subseq = 1;
        Comb c(n);

        for (int i = 0; i < n; ++i) {
            res += (num_subseq * (nums[i] + nums[n - i - 1]) % MOD);
            num_subseq = (2 * num_subseq - c.comb(i, k - 1) + MOD) % MOD;
        }   

        return res % MOD;
    }
};