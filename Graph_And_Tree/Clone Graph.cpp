/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 // Idea: copy the graph recersivly, use a vector to track the created nodes.
class Solution {
public:

	UndirectedGraphNode* getNodeByLabel(std::vector<UndirectedGraphNode*> nodes, int label) {
		for (int i = 0; i < nodes.size(); ++i)
		{
			if(nodes[i]->label == label)
				return nodes[i];
		}
		return NULL;
	}

	UndirectedGraphNode* cloneNode(UndirectedGraphNode *node, 
		std::vector<UndirectedGraphNode*>* created_node){
		if(node == NULL) return NULL;

		UndirectedGraphNode* clone_node = getNodeByLabel(*created_node, node->label);
		if(clone_node != NULL) return clone_node;

		clone_node = new UndirectedGraphNode(node->label);
		created_node->push_back(clone_node);

		for (int i = 0; i < node->neighbors.size(); ++i)
		{
			UndirectedGraphNode* node_neighbor = node->neighbors[i];
			UndirectedGraphNode* clone_neighbor = getNodeByLabel(*created_node, node_neighbor->label);
			if(clone_neighbor == NULL)
			{	
				clone_neighbor = cloneNode(node_neighbor, created_node);	
			}
			clone_node->neighbors.push_back(clone_neighbor);
		}
		return clone_node;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        std::vector<UndirectedGraphNode*> created_nodes;
        return cloneNode(node, &created_nodes);
    }
};