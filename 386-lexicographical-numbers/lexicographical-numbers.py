class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []

        def generate(curr, limit):
            if curr > limit:
                return
            
            res.append(curr)

            for next_digit in range(10):
                next_num = curr * 10 + next_digit

                if next_num <= limit:
                    generate(next_num, limit)
                else:
                    break
        
        for start in range(1, 10):
            generate(start, n)
        
        return res