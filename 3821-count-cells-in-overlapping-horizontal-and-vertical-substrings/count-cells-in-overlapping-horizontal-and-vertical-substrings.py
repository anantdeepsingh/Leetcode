class Solution:
    def search(self, pattern: str, text: str) -> list:
        res = []
        m, n = len(pattern), len(text)
        for i in range(n - m + 1):
            if text[i:i+m] == pattern:
                res.append(i)
        return res
    
    def countCells(self, grid: list, pattern: str) -> int:
        n = len(grid)
        m = len(grid[0])
        
        s1 = ''.join(grid[i][j] for i in range(n) for j in range(m))
        s2 = ''.join(grid[i][j] for j in range(m) for i in range(n))
        
        len_pat = len(pattern)
        ind1 = self.search(pattern, s1)
        ind2 = self.search(pattern, s2)
        
        arr1 = [0] * (n * m + 2)
        arr2 = [0] * (n * m + 2)
        
        for it in ind1:
            arr1[it] += 1
            arr1[it + len_pat] -= 1
        
        for it in ind2:
            arr2[it] += 1
            arr2[it + len_pat] -= 1
        
        for i in range(1, n * m):
            arr1[i] += arr1[i-1]
            arr2[i] += arr2[i-1]
        
        grid1 = [[0] * m for _ in range(n)]
        grid2 = [[0] * m for _ in range(n)]
        
        for i in range(n * m):
            row1, col1 = divmod(i, m)
            if arr1[i] > 0:
                grid1[row1][col1] = 1
        
        for i in range(n * m):
            row2, col2 = i % n, i // n
            if arr2[i] > 0:
                grid2[row2][col2] = 1
        
        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid1[i][j] and grid2[i][j]:
                    cnt += 1
        
        return cnt
