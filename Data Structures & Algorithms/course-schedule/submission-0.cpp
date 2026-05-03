class Solution {
public:
    // Kahns Algorithm (Topological sort)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){
            return true;
        }
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses,0);
        // Indegree is direct to dependent node/course.
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        if(q.empty()){
            return false;
        }
        int len = 0;
        // All courses which are depndent on another
        while(!q.empty()){
            int course = q.front();
            q.pop();
            len++;
            for(int i=0;i<graph[course].size();++i){
                indegree[graph[course][i]]--;
                if(indegree[graph[course][i]]==0)
                    q.push(graph[course][i]);
            }
        }
        //cout<<"len:"<<len<<endl;
        if(len==numCourses){        
            return true;
        }
        return false;
    }
};