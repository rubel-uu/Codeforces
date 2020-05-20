#include<bits/stdc++.h>
using namespace std;
#define M 1005
#define INF 1e6
int dis[M];
bool vis[M];
vector<int>G[M];
void bfs(int source)
{
    vis[source]=1;
    dis[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
    int node=q.front();
    q.pop();
    for(int i=0;i<G[node].size();i++)
    {
        int next=G[node][i];
        if(vis[next]==0)
        {
            vis[next]=1;
            dis[next]=dis[node]+1;
            q.push(next);
        }
    }

    }
}
void reset()
{
    for(int i=0;i<M;i++)
    {
        G[i].clear();
        vis[i]=0;
        dis[i]=0;
    }
}
int main()
{

    ///freopen("input.txt","r",stdin);

    int t,nodes,edges;
    cin>>t;
    while(t--)
    {
        reset();

        cin>>nodes>>edges;
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int source;
        cin>>source;
        bfs(source);
        for(int i=1;i<=nodes;i++)
        {
           if(vis[i]==0)
           {
               cout<<"-1"<<" ";
           }
           else if(i!=source&&vis[i]==1)
           {
               cout<<dis[i]*6<<" ";
           }



        }
        cout<<endl;

    }
    return 0;
}
