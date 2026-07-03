class Solution {
public:
    using ll = long long;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);

        int hi = 0;

        for(auto &e:edges){

            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj[u].push_back({v,w});
            indegree[v]++;

            hi=max(hi,w);
        }

        // Topological order
        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<int> topo;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v,w]:adj[u]){

                if(--indegree[v]==0)
                    q.push(v);
            }
        }

        auto check=[&](int mid){

            const ll INF=4e18;

            vector<ll> dp(n,INF);

            dp[0]=0;

            for(int u:topo){

                if(dp[u]==INF)
                    continue;

                if(u!=0 && u!=n-1 && !online[u])
                    continue;

                for(auto &[v,w]:adj[u]){

                    if(w<mid)
                        continue;

                    if(v!=n-1 && !online[v])
                        continue;

                    dp[v]=min(dp[v],dp[u]+w);
                }
            }

            return dp[n-1]<=k;
        };

        int lo=0;
        int ans=-1;

        while(lo<=hi){

            int mid=lo+(hi-lo)/2;

            if(check(mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans;
    }
};