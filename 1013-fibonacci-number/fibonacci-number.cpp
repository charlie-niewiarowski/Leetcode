class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0; 
        
        int smaller = 0; int larger = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = larger;
            larger += smaller;
            smaller = tmp;
        }
        return larger;
    }
};