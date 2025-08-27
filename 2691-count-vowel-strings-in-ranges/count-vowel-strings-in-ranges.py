class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set('aeiou')
        prefix_sums = [0] * (len(words) + 1)
        prev = 0

        for i, w in enumerate(words):
            if w[0] in vowels and w[-1] in vowels:
                prev += 1
            prefix_sums[i + 1] = prev
        
        res = [0] * len(queries)
        for i, (l, r) in enumerate(queries):
            res[i] = prefix_sums[r + 1] - prefix_sums[l]
        return res