#include <iostream>
#include <vector>
using namespace std;

// 全局访问标记，也可以放到函数参数里
vector<bool> visited;

// dfs：u 当前访问的节点
void dfs(const vector<vector<int>>& adj, int u) {
    cout << u << " ";       // 访问输出节点
    visited[u] = true;      // 标记已访问
    
    // 遍历u所有邻接点
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(adj, v);
        }
    }
}

int main() {
    int n = 5; // 节点数：0~4
    // 邻接表 adj[u]存u相连的所有节点
    vector<vector<int>> adj(n);
    // 建边 无向图，双向加边
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
 

    visited.assign(n, false);
    cout << "DFS遍历结果：";
    // 如果图不连通，要循环所有节点防止漏掉连通分量
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(adj, i);
        }
    }
    return 0;
}
