#include<bits/stdc++.h>
using namespace std;
// sink node is a node with no outgoing edges.
int cntsinknode(int nd, int edg, int *src, int *dst) {
    int vis[nd] = {0}, cnt = 0;
    for(int i = 0; i < edg; i++) vis[src[i]] = 1;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(!vis[i]) ++cnt;
    }
    /* int arr[node] = {0};
    for(int i = 0; i < node; i++) arr[src[i]] = 1;
    for(int i = 1; i <= node; i++){
        if(arr[i] == 0) cnt++;
    } */
    return cnt;
}
