import sys
distance = int(sys.stdin.readline())
clubno = int(sys.stdin.readline())
clubs = []
for i in range(clubno):
    a = int(sys.stdin.readline())
    clubs.append(a)
dict = {}
def golf(distance, clubs):
    if distance in clubs:
        return 1
    if distance < 0:
        return -1
    if distance in dict:
        return dict[distance]
    else:
        a = []
        for c in clubs:
            strokes = golf(distance - c, clubs)
            dict[distance-c] = strokes
            if strokes == -1:
                # no valid path found, do nothing
                pass
            else:
                a.append(strokes + 1)
        if not a:
            return -1
        return min(a)
strokes = golf(distance, clubs)
if strokes != -1:
    print("Roberta wins in " + str(strokes) + " strokes.")
else:
    print("Roberta acknowledges defeat.")
