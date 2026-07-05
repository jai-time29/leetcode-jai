class Solution {
public:

    static const int MOD=1e9+7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n=board.size();

        vector<vector<int>> score(n,vector<int>(n,-1));
        vector<vector<int>> ways(n,vector<int>(n,0));

        score[n-1][n-1]=0;
        ways[n-1][n-1]=1;

        for(int i=n-1;i>=0;i--){

            for(int j=n-1;j>=0;j--){

                if(board[i][j]=='X')
                    continue;

                if(i==n-1 && j==n-1)
                    continue;

                int mx=-1;

                // down
                if(i+1<n)
                    mx=max(mx,score[i+1][j]);

                // right
                if(j+1<n)
                    mx=max(mx,score[i][j+1]);

                // diagonal
                if(i+1<n && j+1<n)
                    mx=max(mx,score[i+1][j+1]);

                if(mx==-1)
                    continue;

                long long cnt=0;

                if(i+1<n && score[i+1][j]==mx)
                    cnt+=ways[i+1][j];

                if(j+1<n && score[i][j+1]==mx)
                    cnt+=ways[i][j+1];

                if(i+1<n && j+1<n && score[i+1][j+1]==mx)
                    cnt+=ways[i+1][j+1];

                ways[i][j]=cnt%MOD;

                int val=0;

                if(board[i][j]>='1' && board[i][j]<='9')
                    val=board[i][j]-'0';

                score[i][j]=mx+val;
            }
        }

        if(ways[0][0]==0)
            return {0,0};

        return {score[0][0],ways[0][0]};
    }
};