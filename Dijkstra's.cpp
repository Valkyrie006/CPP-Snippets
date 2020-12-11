//Shortest dist from source to destination

const int INF = 2147483647;
const int MAX = 5005;
ll D[MAX], N; // Keeps minimum distance to each node from source
vpll G[MAX]; // Adjacency list
 
void dijkstra()
{
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[1] = 0;//Source (in this case we have taken 1)
    priority_queue<pll ,vpll,greater<pll>> q;
    q.push({0,1});//{dist from source(always 0), source(in this case 1)}
 
    while(!q.empty())
    {
        pll p = q.top();
        q.pop();
 
        ll u = p.S, dist = p.F;
        if(dist > D[u]) 
        	continue;
 
        for(pll pr : G[u])
        {
            ll v = pr.F;
            ll next_dist = dist + pr.S;
 
            if(next_dist < D[v])
            {
                D[v] = next_dist;
                q.push({next_dist,v});
            }
        }
    }
}
