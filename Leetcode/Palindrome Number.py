class Solution:
    def isPalindrome(self, x: int) -> bool:
        palindrome = list(str(x))
        if palindrome == palindrome[::-1]:
            return True
        return False
