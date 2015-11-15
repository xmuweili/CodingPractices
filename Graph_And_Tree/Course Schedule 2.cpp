class Solution {
public:
    
    vector<int> getPrereq(int Courses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        for(int i=0; i<prerequisites.size(); ++i) {
            if(prerequisites[i].first == Courses)
                res.push_back(prerequisites[i].second);
        }
        return res;
    }


    bool unVisited( vector<bool>& visited, int* pos) {
        vector<bool>::iterator uit = find(visited.begin(), visited.end(), false);
        if(uit == visited.end()) {
            return false;
        }
        *pos = uit - visited.begin();
        return true;
    }
    
    
    bool visit(int course, vector<vector<int>>& prerequisites,
               vector<bool>* tracking, vector<bool>* visited, vector<int>* order) {
        if(tracking->at(course)) return true;
        if(visited->at(course)) return false;
        tracking->at(course) = true;
        vector<int> pre_courses = prerequisites[course];
        for(int i=0; i<pre_courses.size(); ++i) {
            if(visit(pre_courses[i], prerequisites, tracking, visited, order)) {
                return true;
            }
        }
        tracking->at(course) = false;
        visited->at(course) = true;
        order->push_back(course);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> prerequisites_list;
        for(int i=0; i<numCourses; ++i)
            prerequisites_list.push_back(getPrereq(i,prerequisites));
        
        vector<bool> tracking(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> order;
        int pos;
        while(unVisited(visited, &pos)){
            if(visit(pos, prerequisites_list, &tracking, &visited, &order))
            {
                order.clear();
                return order;
            }

        }
        return order;
    }
};