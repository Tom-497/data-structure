#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int x):val(x){}
};

// DFS求多叉树层数
int getMultiTreeLevel(Node* root) {
    if(!root) return 0;
    int maxChild = 0;
    for(auto child : root->children){
        maxChild = max(maxChild, getMultiTreeLevel(child));
    }
    return maxChild + 1;
}

// BFS多叉树
int getMultiTreeLevelBFS(Node* root){
    if(!root) return 0;
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int sz = q.size();
        level++;
        for(int i=0;i<sz;i++){
            auto cur = q.front(); q.pop();
            for(auto c : cur->children){
                q.push(c);
            }
        }
    }
    return level;
}


int main()
{
    return 0;
}