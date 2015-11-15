// Idea: the loop detection problem. 
// 1. Implemenet a function that detect if current node is in loop.
// 2. Travel all the nodes. 
// depth first travel the graph, and detect the loop along the way. 

class Solution {
public:

	std::vector<int> getPreCourses(int course, const vector<pair<int, int>>& prerequisites) {
		std::vector<int> res;
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			if(prerequisites[i].first == course)
				res.push_back(prerequisites[i].second);
		}
		return res;
	}

	bool visit(int course, const vector<pair<int, int>>& prerequisites, 
		std::vector<int>* tracking, std::vector<int>* visited) {
		if(tracking->at(course) == 1) return true;
		if(visited->at(course) == 1) return false;

		tracking->at(course) = 1;
		std::vector<int> pre_course = getPreCourses(course, prerequisites);
		for (int i = 0; i < pre_course.size(); ++i)
		{
			if(visit(pre_course[i], prerequisites, tracking, visited))
				return true;
		}
		tracking->at(course) = 0;
		visited->at(course) = 1;
		return false;
	}

	bool getUnvisited(std::vector<int> visited, int* pos) {

		std::vector<int>::iterator vit = 
		find(visited.begin(), visited.end(), 0);
		if(vit == visited.end()) return false;
		*pos = vit - visited.begin();
		return true;
	}

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        std::vector<int> visited(numCourses, 0);

        int pos;
        while(getUnvisited(visited, &pos))
        {
        	std::vector<int> tracking(numCourses, 0);
        	if(visit(pos, prerequisites, &tracking, &visited))
        		return false;
        }
        return true;
    }
};