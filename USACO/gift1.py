fin = open ('gift1.in', 'r')
fout = open('gift1.out', 'w')
lines = fin.readlines()
np = int(lines[0].strip())
people = {}
counter = 1
for i in range(np):
    people[lines[counter].strip()] = 0
    counter += 1
for i in range(np):
    giver = lines[counter].strip()
    counter += 1
    amount, ng = map(int, lines[counter].strip().split(" "))
    counter += 1
    try:
        adding = amount//ng
        for i in range(ng):
            receiver = lines[counter].strip()
            counter += 1
            people[receiver] += adding
        people[giver] -= amount
        people[giver] += amount - ((amount//ng) * ng)
    except:
        pass
for i in people.keys():
    fout.write(i + " " + str(people[i]) + "\n")
fout.close()
