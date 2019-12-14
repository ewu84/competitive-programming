class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i in '[({':
                stack.append(i)
            else:
                if stack:
                    print("yes")
                    opens = stack.pop()

                    if i == ']' and opens == '[':
                        continue
                    elif i == '}' and opens == '{':

                        continue
                    elif i == ')' and opens == '(':
                        continue
                    else:
                        return False
                else:
                    return False
        if not(stack):
            return True
        else:
            return False
