#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class FlowEdge{
    
    public:
    int v,w,capacity,flow;
    
    FlowEdge(){
    }

    FlowEdge(int v,int w,int capacity)
    {
        this->v=v;
        this->w=w;
        this->capacity=capacity;
        this->flow=0;
    }

    int other (int vertex)
    {
        return vertex == v ? w : v;
    }

    int residualCapacityTo(int vertex)
    {
        return vertex == v ? flow : capacity-flow;
    }
    
    void addResidualFlowTo(int vertex,int delta)
    {
        if(vertex==v)   flow-=delta;
        else flow+=delta;
    }
};

class FlowNetwork{

    public:
    int V;
    vector<vector<FlowEdge*> > adj;

    FlowNetwork(){
    }

    FlowNetwork(int V)
    {
        this->V = V;
        adj = vector<vector<FlowEdge*> >(V);
    }
    void addEdge(FlowEdge *e)
    {
        adj[e->v].push_back(e);
        adj[e->w].push_back(e);
    }
};

class FordFulkerson{
    
    public:
    vector<bool> marked;
    vector<FlowEdge*> edgeTo;
    int value;

    FordFulkerson(){
    }

    FordFulkerson(FlowNetwork &G,int s,int t)
    {
        value=0;

        while(hasAugmentingPath(G,s,t))
        {
            int bottle = 1e9;
            for(int v = t;v!=s;v=edgeTo[v]->other(v))
            {
            //  cout<<v<<" <- ";
                bottle = min(bottle,edgeTo[v]->residualCapacityTo(v));
            }

            for(int v = t;v!=s;v=edgeTo[v]->other(v))
                edgeTo[v]->addResidualFlowTo(v,bottle);

            value+=bottle;            

           // cout<<endl<<"Bottle "<<bottle<<endl;
        }
    }

    bool hasAugmentingPath(FlowNetwork &G,int s,int t)
    {
        marked = vector<bool> (G.V,false);
        edgeTo = vector<FlowEdge*> (G.V);

        queue<int> Q;
        Q.push(s);
        marked[s]=1;
        while(!Q.empty())
        {
            int v = Q.front(); Q.pop();

            for(int i=0;i<G.adj[v].size();i++)
            {
                FlowEdge *e = G.adj[v][i];
                int w = e->other(v);
                if(e->residualCapacityTo(w) > 0 && !marked[w])
                {
                    edgeTo[w]=e;
                    marked[w]=1;
                    Q.push(w);
                }
            }
        }
        return marked[t];
    }
};

int main()
{
    int n,m,s,t,x,y,wt;
    cout<<"enter no of vertices and no of edges\n";
    cin>>n>>m;
    FlowNetwork G(n);
    cout<<"enter edges one per line in x,y,wt format\n";
    while(m--)
    {
        cin>>x>>y>>wt;
        G.addEdge(new FlowEdge(x,y,wt));
    }
    cout<<"enter s and t\n";
    cin>>s>>t;
    FordFulkerson f(G,s,t);
    cout<<f.value<<endl;
}
