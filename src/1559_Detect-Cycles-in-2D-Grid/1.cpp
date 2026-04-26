// 205 ms (< 23.26%), 103.90 MB (< 34.54%)
#include <set>
#include <vector>

class Solution {
public:
    bool containsCycle(std::vector<std::vector<char>>& grid) {
        std::set<std::pair<int, int>> visited = {};
        size_t size_x = grid.size();
        for (int x = 0; x < size_x; x++) {
            size_t size_y = grid[x].size();
            for (int y = 0; y < size_y; y++) {
                if (visited.contains(std::pair<int, int> {x, y})) continue;
                if (dfs(grid, size_x, size_y, x, y, -1, -1, visited)) return true;
            }
        }
        return false;
    }

    // Grid -> Integer -> Integer -> Integer -> Integet -> Integer -> Integer -> Set[(Integer, Integer)] -> Bool
    //  visited.add((x, y))
    //  for (nx, ny) in grid.neigh((x, y)):
    //      if (nx, ny) != (parent_x, parent_y) && grid[nx, ny] == grid[x, y]
    //          if (nx, ny) in visited  return true;
    //          if dfs(grid, size_x, size_y, nx, ny, x, y, visited) return true;
    //  return false
    bool dfs(const std::vector<std::vector<char>>& grid, int size_x, int size_y, int x, int y, int parent_x, int parent_y, std::set<std::pair<int, int>>& visited) {
        std::pair<int, int> current {x, y};
        visited.insert(current);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= size_x || ny < 0 || ny >= size_y) continue;
            if (nx == parent_x && ny == parent_y) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            if (visited.contains(std::pair<int, int> {nx, ny})) return true;
            if (dfs(grid, size_x, size_y, nx, ny, x, y, visited)) return true;
        }
        return false;
    }
};
