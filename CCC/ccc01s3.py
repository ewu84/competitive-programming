class Node:
    def __init__(self, name):
        self.name = name
        self.neighbours = []
    def __repr__(self):
        return "name: {}, neighbours: {}".format(self.name, str([i.name for i in self.neighbours]))
def bfs(start, name):
  visited = []
  queue = []
  queue.append(start)
  while len(queue) > 0:
    current = queue.pop(0)
    if current.name == name:
      return True
    visited.append(current)
    for i in current.neighbours:
      if i not in visited:
        queue.append(i)
road = input()
roads = []
points = {}
while road != '**':
    roads.append(road)
    roade = []
    for point in road:
        if point not in points:
            point = Node(point)
            points[point.name] = point


    points[road[0]].neighbours.append(points[road[1]])
    points[road[1]].neighbours.append(points[road[0]])
    road = input()
bombingroads = []
counter = 0
for road in roads:
    pointa = road[0]
    pointb = road[1]
    newpoints = points
    newpoints[pointa].neighbours.remove(newpoints[pointb])
    newpoints[pointb].neighbours.remove(newpoints[pointa])
    if not(bfs(newpoints[pointa], pointb)):
        counter += 1
        bombingroads.append(road)
    else:
        newpoints[pointa].neighbours.append(newpoints[pointb])
        newpoints[pointb].neighbours.append(newpoints[pointa])
for i in bombingroads:
    print(i)
print("There are " + str(counter) + " disconnecting roads.")

#dont judge i wrote this a loooooooooooong time ago.
