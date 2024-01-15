/*
Problem statement
You are given an undirected graph with 'N' nodes and 'M' edges. The weight of each edge in the graph is one unit.



Given a source vertex 'src', you must return an array 'answer' of length 'N', where 'answer[i]' is the shortest path length between the source vertex 'src' and 'i'th vertex.



Note:
All the nodes are zero-based.
Example:
Input:
N=5, M=5, edges=[(0, 1), (1, 4), (2, 3), (2, 4), (3, 4)], src=1 
Output: 1 0 2 2 1

Explanation: The path from vertices are:-
(1->0) = 1 -> 0, path length is 1.
(1->1) = 1 -> 1, path length is 0.
(1->2) = 1 -> 4 -> 2, the path length is 2.
(1->3) = 1 -> 4 -> 3, path length is 2.
(1->4) = 1 -> 4, the path length is 1.
Hence we return [1, 0, 2, 2, 1]
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 3
0 1
0 3
2 3
0
Sample Output 1:
0 1 2 1
Explanation Of Sample Input 1:
For test case one:
Input:
N=4, M=3, edges=[(0, 1), (0, 3), (2, 3)], src=0 
Output: 0 1 2 1

Explanation: The path from vertices are:-
(0->0) = 0 -> 0, path length is 0.
(0->1) = 0 -> 1, path length is 1.
(0->2) = 0 -> 3 -> 2, path length is 2.
(0->3) = 0 -> 2, path length is 1.
Hence we return [0, 1, 2, 1]
Sample Input 2:
3 3
0 1
1 2 
0 2
2
Sample Output 2:
1 1 0
Constraints:
1 <= N, M <= 10^2
0 <= src, edges[0], edges[0] <= N-1
Time Limit: 1 sec
  */
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    
    vector<int>adj[n];
    vector<int>dist(n);
   for(int i=0;i<n;i++){
       dist[i]=1e9;//initiaze with 1e9 values.
   }
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);//since it is undirected we can push both of them vertex
        adj[i[1]].push_back(i[0]);
    }
    dist[src]=0;//starting from 0th node
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:adj[node]){//iterating adjacent vertex of (int node=q.front()) check for distances
            if(dist[node]+1<dist[it]){
                dist[it]=dist[node]+1;//taking min distance of them 
                q.push(it);
            }
        }
    }
    vector<int>result(n,-1);//since we are returning -1 if not found anything ,
    for(int i=0;i<dist.size();i++){
        if(dist[i]!=1e9){
            result[i]=dist[i];
        }
    }
    return result;

}
