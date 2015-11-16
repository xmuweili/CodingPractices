#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


void visit(int node, const vector<vector<int>>& edges, 
					 std::vector<bool>* visited, 
					 std::vector<int>* distance) {
	queue<int> visit;
	visit.push(node);
	while(!visit.empty())
	{
		int curr = visit.front();
		if(distance->at(curr-1) == -1)
			distance->at(curr-1) = 0;

		std::vector<int> connnect = edges[curr-1];
		for (int i = 0; i < connnect.size(); ++i)
		{
			int curr_nei = connnect[i];
			if(visited->at(curr_nei-1))
				continue;
			distance->at(curr_nei-1) = distance->at(curr_nei-1) + 6;
			visit.push(curr_nei);
		}
		visit.pop();
		visited->at(curr-1) = true;
	}
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num_test_cases = 0;
    cin >> num_test_cases;
    // cout << num_test_cases;
    for(int i=0; i<num_test_cases; ++i)
    {
    	int num_nodes, num_edges;
    	vector<vector<int>> edges;
    	edges.resize(num_nodes);
    	cin >> num_nodes >> num_edges;
    	for (int e = 0; e < num_edges; ++e)
    	{
    		int source, target;
    		cin >> source >> target;
    		edges[source-1].push_back(target);
    		edges[target-1].push_back(source);
    	}
    	int starting_node;
    	cin >> starting_node;
    	std::vector<int> distance(num_nodes, -1);
    	std::vector<bool> visited(num_nodes, false);

    	visit(starting_node, edges, &visited, &distance);
    	for (int j = 0; j < num_nodes; ++j)
    	{
    		if(j == starting_node - 1) continue;
    		cout << distance[j] << " ";
    	}
    }
    return 0;
}
