// C++ implementation to find the
// shortest path in a complement graph

#include <bits/stdc++.h>
using namespace std;

const int inf = 100000;

void bfs(int start, int n, int m,
		map<pair<int, int>, int> edges)
{
	int i;

	// List of undiscovered vertices
	// initially it will contain all
	// the vertices of the graph
	set<int> undiscovered;

	// Distance will store the distance
	// of all vertices from start in the
	// complement graph
	vector<int> distance_node(10000);

	for (i = 1; i <= n; i++) {

		// All vertices are undiscovered
		undiscovered.insert(i);

		// Let initial distance be infinity
		distance_node[i] = inf;
	}

	undiscovered.erase(start);
	distance_node[start] = 0;
	queue<int> q;

	q.push(start);

	// Check if queue is not empty and the
	// size of undiscovered vertices
	// is greater than 0
	while (undiscovered.size() && !q.empty()) {
		int cur = q.front();
		q.pop();

		// Vector to store all the complement
		// vertex to the current vertex
		// which has not been
		// discovered or visited yet.
		vector<int> complement_vertex;

		for (int x : undiscovered) {
			if (edges.count({ cur, x }) == 0)
				complement_vertex.push_back(x);
		}
		for (int x : complement_vertex) {

			// Check if optimal change
			// the distance of this
			// complement vertex
			if (distance_node[x]
				> distance_node[cur] + 1) {
				distance_node[x]
					= distance_node[cur] + 1;
				q.push(x);
			}

			// Finally this vertex has been
			// discovered so erase it from
			// undiscovered vertices list
			undiscovered.erase(x);
		}
	}
	// Print the result
	for (int i = 1; i <= n; i++)
		cout << distance_node[i] << " ";
}

// Driver code
int main()
{
	// n is the number of vertex
	// m is the number of edges
	// start - starting vertex is 1
	int n = 5, m = 4;

	// Using edge hashing makes the
	// algorithm faster and we can
	// avoid the use of adjacency
	// list representation
	map<pair<int, int>, int> edges;

	// Initial edges for
	// the original graph
	edges[{ 1, 3 }] = 1,
				edges[{ 3, 1 }] = 1;
	edges[{ 1, 2 }] = 1,
				edges[{ 2, 1 }] = 1;
	edges[{ 3, 4 }] = 1,
				edges[{ 4, 3 }] = 1;
	edges[{ 3, 5 }] = 1,
				edges[{ 5, 3 }] = 1;

	bfs(1, n, m, edges);

	return 0;
}
