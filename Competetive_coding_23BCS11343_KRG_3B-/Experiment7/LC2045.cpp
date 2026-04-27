#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define P pair<int,int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        // adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // shortest & second shortest times
        vector<int> d1(n + 1, INT_MAX), d2(n + 1, INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(make_pair(0, 1));
        d1[1] = 0;

        while (!pq.empty()) {
            P current = pq.top();
            pq.pop();
            int currTime = current.first;
            int node = current.second;

            // 🚦 WAIT LOGIC (DON'T MODIFY currTime DIRECTLY)
            int departTime = currTime;
            int cycle = departTime / change;
            if (cycle % 2 == 1) {
                departTime = (cycle + 1) * change;
            }

            for (auto &nbr : adj[node]) {
                int newTime = departTime + time;

                if (newTime < d1[nbr]) {
                    d2[nbr] = d1[nbr];
                    d1[nbr] = newTime;
                    pq.push(make_pair(newTime, nbr));
                }
                else if (newTime > d1[nbr] && newTime < d2[nbr]) {
                    d2[nbr] = newTime;
                    pq.push(make_pair(newTime, nbr));
                }
            }
        }

        return d2[n];
    }
};

int main() {
    Solution obj;

    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int time, change;
    cout << "Enter time per edge: ";
    cin >> time;
    cout << "Enter signal change time: ";
    cin >> change;

    int ans = obj.secondMinimum(n, edges, time, change);

    cout << "Second Minimum Time: " << ans << endl;

    return 0;
}