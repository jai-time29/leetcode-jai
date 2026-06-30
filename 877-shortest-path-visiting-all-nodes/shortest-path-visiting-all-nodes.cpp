class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();

        int target = (1<<n)-1;


        queue<pair<int,int>> q;


        vector<vector<int>> visited(n, vector<int>(1<<n,0));


        // start from every node
        for(int i=0;i<n;i++) {

            int mask = (1<<i);

            q.push({i,mask});

            visited[i][mask]=1;
        }


        int steps = 0;



        while(!q.empty()) {


            int size = q.size();


            while(size--) {


                auto [node,mask] = q.front();
                q.pop();



                // all nodes visited
                if(mask == target)
                    return steps;



                for(int next : graph[node]) {


                    int newMask = mask | (1<<next);


                    if(!visited[next][newMask]) {

                        visited[next][newMask]=1;

                        q.push({next,newMask});
                    }
                }

            }


            steps++;
        }


        return -1;
    }
};