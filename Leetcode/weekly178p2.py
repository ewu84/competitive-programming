import functools
class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        freq = [[0 for i in range(26)] for j in range(26)]
        for i in votes:
            for idx, j in enumerate(i):
                freq[ord(j)-65][idx] += 1
        chars = list(votes[0])
        def comp(a, b):
            for i in range(26):
                if freq[ord(a) - 65][i] >  freq[ord(b) - 65][i]:
                    return 1
                elif  freq[ord(a) - 65][i] <  freq[ord(b) - 65][i]:
                    return -1
            if ord(a) < ord(b):
                return 1
            else:
                return -1
                    
        chars = sorted(chars, key = functools.cmp_to_key(comp), reverse=True)
        return ''.join(chars)
#https://leetcode.com/problems/rank-teams-by-votes/
#wasted so much time lol
