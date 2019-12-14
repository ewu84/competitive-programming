class Solution:
    def romanToInt(self, s: str) -> int:
        dictionary = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        counts = 0
        for i in dictionary.keys():
            a = s.count(i)
            counts += (dictionary[i] * a)
  
        exceptions = ['IV', 'IX', 'XL', 'XC', 'CD', 'CM']
        for i in exceptions:
            a = s.count(i)
            counts -= (dictionary[i[0]] * 2) * a
            print(counts)
        return counts
        
