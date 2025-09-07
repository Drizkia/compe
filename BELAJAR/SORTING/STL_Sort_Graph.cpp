#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; 
    cin >> N;

    // first  = weight (bobot)
        // second = pair(node1, node2)
    vector<pair<int, pair<int, int>>> edges(N);

    // Input edge
    // Structured binding: [width, edge] akan memecah pair<int, pair<int,int>>
    for (auto &[bobot, edge] : edges) {
        // Input: node1 node2 weight
        cin >> edge.first >> edge.second >> bobot;
        // edge.first  -> node1
        // edge.second -> node2
        // bobot       -> bobot edge
    }
    sort(edges.begin(), edges.end());
    for (const auto &[width, edge] : edges) {
        // Cetak dalam format: (node1, node2): weight
        cout << edge.first << " " << edge.second << " " << width;
    }

    vector<array<int, 3>> Graph;
	// vector<vector<int>> edges;  // also works, but is slower
	for (int e = 0; e < N; e++) {
		int a, b;
		int width;
		cin >> a >> b >> width;
		Graph.push_back({width, a, b});
	}
	sort(Graph.begin(), Graph.end());
}