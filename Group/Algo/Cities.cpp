#include <bits/stdc++.h>
#define INF 99999
using namespace std;
 
// Number of vertices in the graph
#define V 4
 
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance
// array
void printSolution(int dist[][V])
{
    printf("Following matrix shows the shortest distances"
           " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
// Solves the all-pairs shortest path problem using
// Johnson's algorithm
void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
 
    /* Initialize the solution matrix same as input graph
       matrix. Or we can say the initial values of shortest
       distances are based
       on shortest paths considering no intermediate vertex.
     */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of
      intermediate vertices.
      ---> Before start of a iteration, we have shortest
      distances between all pairs of vertices such that the
      shortest distances consider only the vertices in set
      {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is
      added to the set of
      intermediate vertices and the set becomes {0, 1, 2, ..
      k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
    printSolution(dist);
}
 
// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
             10
        (0)------->(3)
         |         /|\
       5 |          |
         |          | 1
        \|/         |
        (1)------->(2)
             3           */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}
// find last man standing
#include <bits/stdc++.h>
using namespace std;
int josephusCircle(int n, int k){
    list<int>l;
    for(int i=0;i<n;i++)
        l.push_back(i);
      
    auto it = l.begin();  
    while(l.size()>1){
        for(int i=1;i<k;i++){
            it++;
             
            if(it==l.end()){
              //if iterator reaches the end,then we change it to begin of the list
                it = l.begin();
            }
        }
         it = l.erase(it);
          
         if(it==l.end()){
           //if iterator reaches the end,then we change it to begin of the list
                it = l.begin();
            }
    }
    return l.front();
}
int main()
{
   int n=14,k=2;
      cout<<josephusCircle(n,k)<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int maxindex(int* dist, int n)
{
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[mi])
            mi = i;
    }
    return mi;
}
void selectKcities(int n, int weights[4][4], int k)
{
    int* dist = new int[n];
    vector<int> centers;
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    // index of city having the maximum distance to it's closest center
    int max = 0;
    for (int i = 0; i < k; i++) {
        centers.push_back(max);
        for (int j = 0; j < n; j++) {
            // updating the distance of the cities to their closest centers
            dist[j] = min(dist[j], weights[max][j]);
        }
        // updating the index of the city with the maximum distance to it's closest center
        max = maxindex(dist, n);
    }
    // Printing the maximum distance of a city to a center that is our answer
    cout << endl << dist[max] << endl;
    // Printing the cities that were chosen to be made centers
    for (int i = 0; i < centers.size(); i++) {
        cout << centers[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 4;
    int weights[4][4] = { { 0, 4, 8, 5 },
    { 4, 0, 10, 7 }, { 8, 10, 0, 9 },
   { 5, 7, 9, 0 } };
    int k = 2;
    selectKcities(n, weights, k);
}
