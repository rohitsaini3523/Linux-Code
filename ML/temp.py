def h(n,start,goal):
        """ Calculates the different between the given puzzles """
        temp = 0
        for i in range(0,n):
            for j in range(0,n):
                if start[i][j] != goal[i][j] and start[i][j] != '_':
                    temp += 1
        return temp
start = [[2,8,3],[1,6,4],['_',7,5]]
goal = [[1,2,3],[8,'_',4],[7,6,5]]
print(h(3,start,goal))