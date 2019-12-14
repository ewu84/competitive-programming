class Solution:
    def intToRoman(self, n: int) -> str:
        dictionary = {'1': 'I', '4':'IV', '5': 'V', '9': 'IX', '10': 'X', '40':'XL', '50':'L', '90':'XC',  '100': 'C', '400':'CD', '500':'D', '900':'CM', '1000': 'M'}
        xpanded = []
        n = str(n)
        for idx, x in enumerate(n):
            if x != '0':
                num = x + ('0' * (len(n)-idx-1))
                xpanded.append(num)
        s = ''
  
        for i in xpanded:
       
            if i in dictionary:
                s += dictionary[i]
            elif i[0] in ['6','7','8']:
                sume = '5' + ('0' * (len(i) - 1))
                print(int(i)-int(sume))
                s += dictionary[sume]
                for time in range((int(i) - int(sume))//(int(i)//int(i[0]))):
                    s += dictionary[str(int(i)//int(i[0]))]
            else:
                base = dictionary[str(int(i)//int(i[0]))]
                s += (base * int(i[0]))
        return s
