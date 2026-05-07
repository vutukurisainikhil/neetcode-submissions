class Solution {
public:
    /*
   1. Initialize a queue, Q to keep a track of all the nodes in the graph with 0 in-degree.
   2. Iterate over all the edges in the input and create an adjacency list and also a map of node v/s in-degree.
   3. Add all the nodes with 0 in-degree to Q.
   4. The following steps are to be done until the Q becomes empty.
        1. Pop a node from the Q. Let's call this node, N.
        2. For all the neighbors of this node, N, reduce their in-degree by 1. If any of the nodes' in-degree reaches 0, add it to the Q.
        3. Add the node N to the list maintaining topologically sorted order.
        4. Continue from step 4.1.
*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> indegree(numCourses, 0);
        // creating adjacency matrix
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        // pushing to queue with indegree=0
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // iterating queue and decrementing indegree counter and pushing into queue with indegree=0.
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<graph[node].size();++i){
                indegree[graph[node][i]]--;
                if(indegree[graph[node][i]]==0){
                    q.push(graph[node][i]);
                }
            }
        }
        if(res.size()==numCourses){
            return res;
        }
        return {};
    }
};