import sys
INT_MAX = sys.maxsize

class Edge:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c 

n, e = input().split()
edge_list = []
dist = []

for i in range(int(e)):
    a, b, c = input().split()
    edge_list.append(Edge(a, b, c))

for i in range(int(n)):
    dist.append(INT_MAX)

dist[0] = 0
cycle = False
for i in range(int(n) - 1):
    for ed in edge_list:
        a = int(ed.a)
        b = int(ed.b)
        c = int(ed.c)
        if dist[a] != INT_MAX and dist[a] + c < dist[b]:
            dist[b] = dist[a] + c
    
    for ed in edge_list:
        a = int(ed.a)
        b = int(ed.b)
        c = int(ed.c)
        if dist[a] != INT_MAX and dist[a] + c < dist[b]:
            cycle = True
            break;

if not cycle:
    print("DEBUG::")
    for i in range(int(n)):
        print(f"{i} -> {dist[i]}")
else:
    print("Negative weighted cycle detected")


"""
4 4
0 2 5
0 3 12
2 1 2
1 3 3
"""
"""
4 4
0 1 5
1 2 3
2 3 2
3 1 -6
"""
"""
4 4
0 1 5
0 3 6
1 2 3
2 3 5
"""