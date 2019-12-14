class Solution:

    def reverse(self, x: int) -> int:
        
        if x >= 0:
            reverse = 0 
            while x > 0:     
                remainder = x % 10
                print(str(remainder))
                x = x // 10
                temp = (reverse * 10) + remainder
                reverse = temp
            if reverse < 2**31:
                return reverse
            else:
                return 0 
        else:
            x = list(str(x))
            m = x.pop(0)
            if (-1 * int(''.join(x[::-1]))) >= -1 * (2**31):
                return -1 * int(''.join(x[::-1]))
            else:
                return 0
