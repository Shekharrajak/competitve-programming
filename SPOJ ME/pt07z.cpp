#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> longestPath(vector<vector<int> > adj, int source) {  
    int nodes = adj.size();
    deque<int> q;
    vector<bool> visited(nodes, false);
    vector<int> sourceDist(nodes, 0);
    q.push_back(source);
    visited[source] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop_front();
        for (int i = 0; i < adj[current].size(); ++i) {
            if (!visited[adj[current][i]]) {
                sourceDist[adj[current][i]] = 
                    sourceDist[current] + 1;
                q.push_back(adj[current][i]);
                visited[adj[current][i]] = true;
            }
        }
    }
    int maxIndex = max_element(sourceDist.begin(), 
                   sourceDist.end()) - sourceDist.begin();
    return make_pair(sourceDist[maxIndex], maxIndex);
}

int main() {  
    int nodes;
    cin >> nodes;
    vector<vector<int> > adj(nodes);
    for (int i = 0; i < nodes - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int farthestNode = longestPath(adj, 0).second;
    cout << longestPath(adj, farthestNode).first << "\n";
    return 0;
}
