#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

int Dijkstra(vector<vector<pair<int,int> > > &G,int start,int end){
    
    int N = G.size();
     vector<int>  D(N, 987654321); 
      // distance from start vertex to each vertex

      priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > Q; 
      // priority_queue with reverse comparison operator, 
      // so top() will return the least distance
      // initialize the start vertex, suppose it’s zero
      D[start] = 0;
      Q.push(pair<int,int> (0,start));

      // iterate while queue is not empty
      while(!Q.empty()) {

            // fetch the nearest element
            pair<int,int> top = Q.top();
            Q.pop();
                        
            // v is vertex index, d is the distance
            int v = top.second, d = top.first;
            if(v==end)return D[end];

            // this check is very important
            // we analyze each vertex only once
            // the other occurrences of it on queue (added earlier) 
            // will have greater distance
            if(d <= D[v]) {
                  // iterate through all outcoming edges from v
                  for(vector<pair<int,int> >::iterator it=G[v].begin();it!=G[v].end();it++) {
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              // update distance if possible
                              D[v2] = D[v] + cost;
                              // add the vertex to queue
                              Q.push(pair<int,int>(D[v2], v2));

                        }
                  }
            }
      }
      return D[end];
}
int main(){
    int n,m,a,b,c,s,e;
    cin>>n>>m;
    vector<vector<pair<int,int> > > v(n);
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
    }
    cin>>s>>e;
    cout<<Dijkstra(v,s,e)<<endl;
}

