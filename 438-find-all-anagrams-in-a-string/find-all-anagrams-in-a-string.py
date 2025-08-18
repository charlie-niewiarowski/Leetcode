class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        result = []
        p_count = Counter(p)
        window_count = Counter()

        for i in range(len(s)):
            window_count[s[i]] += 1

            if i>=len(p):
                left =s[i-len(p)]
                window_count[left] -= 1
                if window_count[left] == 0:
                    del window_count[left]
            if window_count == p_count:
                result.append(i-len(p)+1)
        return result
