class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        if n <= 1:
            return True

        i = 0
        j = n - 1

        while i < j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() != s[j].lower():
                    return False
                i += 1
                j -= 1
            
            elif s[i].isalnum():
                j -= 1
            else:
                i += 1

        return True        
        