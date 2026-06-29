class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<int> visited(n,0);

        queue<int> q;

        q.push(0);
        visited[0]=1;


        while(!q.empty()) {

            int room=q.front();
            q.pop();


            for(int key: rooms[room]) {

                if(!visited[key]) {

                    visited[key]=1;
                    q.push(key);
                }
            }
        }


        for(int x: visited) {

            if(x==0)
                return false;
        }


        return true;
    }
};