fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
lines = fin.readlines()
comet = lines[0].strip()
group = lines[1].strip()
alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
com = 1
grou = 1
for i in comet:
    ind = alphabet.find(i)
    com *= (ind+1)
for i in group:
    ind = alphabet.find(i)
    grou *= (ind+1)
if grou % 47 == com % 47:
    fout.write("GO\n")
    fout.close()
else:
    fout.write("STAY\n")
    fout.close()
