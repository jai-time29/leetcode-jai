class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n,-1));

        queue<pair<int,int>> q;


        // multi source BFS
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {

                if(grid[i][j]==1) {

                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }


        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};



        while(!q.empty()) {

            auto [x,y]=q.front();
            q.pop();


            for(int k=0;k<4;k++) {

                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n 
                   && dist[nx][ny]==-1) {

                    dist[nx][ny]=dist[x][y]+1;

                    q.push({nx,ny});
                }
            }
        }



        // max heap
        priority_queue<
            tuple<int,int,int>
        > pq;


        vector<vector<int>>vis(n,vector<int>(n,0));


        pq.push({dist[0][0],0,0});

        vis[0][0]=1;



        while(!pq.empty()) {


            auto [safe,x,y]=pq.top();
            pq.pop();



            if(x==n-1 && y==n-1)
                return safe;



            for(int k=0;k<4;k++) {

                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n 
                   && !vis[nx][ny]) {


                    vis[nx][ny]=1;


                    pq.push({
                        min(safe,dist[nx][ny]),
                        nx,
                        ny
                    });
                }
            }
        }


        return 0;
    }
};