class Solution {
public:

    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int totalKeys = 0;

        queue<tuple<int,int,int,int>> q;


        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n, vector<bool>(64,false))
        );


        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {


                if(grid[i][j]=='@') {

                    q.push({i,j,0,0});
                    vis[i][j][0]=true;
                }


                if(grid[i][j]>='a' && grid[i][j]<='f')
                    totalKeys++;
            }
        }


        int target = (1<<totalKeys)-1;


        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};



        while(!q.empty()) {


            auto [x,y,mask,dist]=q.front();
            q.pop();



            if(mask==target)
                return dist;



            for(int k=0;k<4;k++) {


                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;


                char c=grid[nx][ny];


                if(c=='#')
                    continue;



                int newMask=mask;



                // key
                if(c>='a' && c<='f') {

                    newMask |= (1<<(c-'a'));
                }



                // lock
                if(c>='A' && c<='F') {

                    if((mask & (1<<(c-'A'))) == 0)
                        continue;
                }



                if(!vis[nx][ny][newMask]) {

                    vis[nx][ny][newMask]=true;

                    q.push({
                        nx,
                        ny,
                        newMask,
                        dist+1
                    });
                }
            }
        }


        return -1;
    }
};