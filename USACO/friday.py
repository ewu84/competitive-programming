"""
ID: evan.be1
LANG: PYTHON3
TASK: friday
"""
fin = open ('friday.in', 'r')
fout = open ('friday.out', 'w')
n = int(fin.readline().strip())
def isleap(year):
    if year % 100 == 0:
        return year % 400 == 0
    else:
        return year % 4 == 0
days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
leap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
freq = [0 for i in range(7)]
cur = 0
for i in range(1900, 1900+n):
    for j in range(12):
        freq[(cur+12)%7] += 1
        if isleap(i):
            cur += leap[j]
        else:
            cur += days[j]
s = str(freq[5]) + " " + str(freq[6]) + " " + str(freq[0]) + " " + str(freq[1]) + " " + str(freq[2]) + " " + str(freq[3]) + " " + str(freq[4])
fout.write(s + "\n")

        
