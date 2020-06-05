// Snakes and Ladders - Leetcode
// Link - https://leetcode.com/problems/snakes-and-ladders/
// Another interesting solution - https://linlaw0229.github.io/2018/10/25/909-Snakes-and-Ladders/




class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board.size() == 0) return 0;
        int n = board.size();
        bool vis[n*n + 1];
        memset(vis, false, sizeof vis);
        int steps[n*n + 1];
        memset(steps, 0, sizeof steps);
        queue<int> q;
        q.push(1);
        steps[1] = 0;
        vis[1] = true;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 1; i<=6; i++){
                int next = u + i;
                int r = getRow(next, n);
                int c = getCol(next, n);
                if(board[r][c] != -1){
                    next = board[r][c];
                }
                if(vis[next]){
                    continue;
                }
                vis[next] = true;
                q.push(next);
                steps[next] = steps[u] + 1;
                if(next == n*n)
                    return steps[next];
            }
        }
        
        return -1;
    }
    
    
    
    
    int getRow(int v, int n){
        return n-1-(v-1)/n;
    }
    int getCol(int v, int n){
        return (((v-1)/n) % 2 == 0) ? ((v-1)%n) : (n-1-(v-1)%n);
    }
};