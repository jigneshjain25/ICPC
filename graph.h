/*Floyd warshall algo*/
let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
for each vertex v
   dist[v][v] ← 0
for each edge (u,v)
   dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
for k from 1 to |V|
   for i from 1 to |V|
      for j from 1 to |V|
         if(dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];

/*
 * Articulation Points finding algorithm using dfs
 * An articulation point is a vertex in a graph, removal
 * of which disconnects the graph (into two or more disjoint 
 * graphs)
 * Sample Implementation : spoj/problems/SUBMERGE
 */
            

ArtPt(v){ 
    color[v] = gray;
    // v initially can only climb up to itself
    Low[v] = d[v] = ++time;
    for all w in Adj(v) do {
        if (color[w] == white) {
            pred[w] = v;
            ArtPt(w);
            // When ArtPt(w) is completed, Low[w] stores the
            // lowest value it can climb up for a subtree
            // rooted at w.
            // Recall v is the parent of w.
            if (pred [v] == NULL) {
                // v has no predecessor , so v is the root.
                // apply observation 1.
                if ('w' is v's second child) output v;
            }
            else if (Low[w] >= d[v]) output v;
            // subtree rooted at w can't climb higher than v
            // apply observation 3.
            // update Low[v] if a children subtree can
            // climb higher
            Low[v] = min(Low[v], Low[w]);
        }
        else if (w != pred[v]) { // (v, w) is a back edge
            // update Low[v] if a back edge climbs higher
            Low[v] = min(Low[v], d[w]);
        }
    }
    color[v] = black;
}



function BellmanFord(list vertices, list edges, vertex source)::weight[],predecessor[]
   // This implementation takes in a graph, represented as lists of vertices and edges,
   // and fills two arrays (weight and predecessor) with shortest-path (less cost/weight/metric) information

   // Step 1: initialize graph
   for each vertex v in vertices:
       if v is source then weight[v] := 0
       else weight[v] := infinity
       predecessor[v] := null

   // Step 2: relax edges repeatedly
   for i from 1 to size(vertices)-1:
       for each edge (u, v) with weight w in edges:
           if weight[u] + w < weight[v]:
               weight[v] := weight[u] + w
               predecessor[v] := u

   // Step 3: check for negative-weight cycles
   for each edge (u, v) with weight w in edges:
       if weight[u] + w < weight[v]:
           error "Graph contains a negative-weight cycle"
   return weight[],predecessor[]
