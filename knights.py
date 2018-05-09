from queue import *

def knightsNextMoves(src):
    moves = list();
    if (src%8 != 0):
        if (src-17 >= 0):
            moves.append(src-17)
        if (src+15 <= 63):
            moves.append(src+15)
    if (src%8 >= 2):
        if (src-10 >= 0):
            moves.append(src-10)
        if (src+6 <= 63):
            moves.append(src+6)
    if (src%8 != 7):
        if (src-15 >= 0):
            moves.append(src-15)
        if (src+17 <= 63):
            moves.append(src+17)
    if (src%8 <= 5):
        if (src-6 >= 0):
            moves.append(src-6)
        if (src+10 <= 63):
            moves.append(src+10)
    return moves

def answer(src, dest):
    # your code here
    bfs = Queue(maxsize=1000)
    bfs.put({src,0})
    visited = set()
    
    while( not bfs.empty() ):
        [cell, depth] = bfs.get()
        visited.add(cell)
        for c in knightsNextMoves(cell):
            if c is dest:
                return depth+1
            if c not in visited:
                bfs.put({c,depth+1})
    
    return -1


