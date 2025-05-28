from collections import deque
from typing import List

class Solution:
    def result1(self, adj: List[List[int]], n: int, ind: int) -> int:
        q = deque()
        dist = [0] * n
        vis = [0] * n
        q.append(ind)
        vis[ind] = 1
        cnt = 0

        while q:
            node = q.popleft()
            if dist[node] % 2 == 0:
                cnt += 1
            for it in adj[node]:
                if not vis[it]:
                    vis[it] = 1
                    dist[it] = dist[node] + 1
                    q.append(it)

        print(dist)
        return cnt

    def result2(self, adj: List[List[int]], n: int, ind: int) -> int:
        q = deque()
        dist = [0] * n
        vis = [0] * n
        q.append(ind)
        vis[ind] = 1
        cnt = 0

        while q:
            node = q.popleft()
            if dist[node] % 2 == 1:
                cnt += 1
            for it in adj[node]:
                if not vis[it]:
                    vis[it] = 1
                    dist[it] = dist[node] + 1
                    q.append(it)

        print(dist)
        return cnt

    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        s1 = len(edges1)
        n = s1 + 1
        s2 = len(edges2)
        m = s2 + 1
        adj1 = [[] for _ in range(n)]
        adj2 = [[] for _ in range(m)]

        for u, v in edges1:
            adj1[u].append(v)
            adj1[v].append(u)

        for u, v in edges2:
            adj2[u].append(v)
            adj2[v].append(u)

        node1 = 0
        node2 = adj1[0][0] if adj1[0] else 0  # Handle empty adjacency

        lev0 = self.result1(adj1, n, node1)
        lev1 = self.result1(adj1, n, node2)
        print(lev0, lev1)

        n2 = adj2[node1][0] if adj2[node1] else 0  # Handle empty adjacency

        t = self.result2(adj2, m, node1)
        t = max(t, self.result2(adj2, m, n2))

        ans = [0] * n
        q = deque()
        q.append((0, 0))
        vis = [0] * n
        vis[0] = 1

        while q:
            node, lev = q.popleft()
            ans[node] = lev0 + t if lev % 2 == 0 else lev1 + t

            for it in adj1[node]:
                if not vis[it]:
                    vis[it] = 1
                    q.append((it, lev + 1))

        return ans
