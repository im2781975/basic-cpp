// count walks from u to v with exactly k edges
#define nd 4
int countwalks(int graph[][nd], int u, int v, int k) {
    int count[nd][nd][k + 1];
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < nd; i++) {
            for (int j = 0; j < nd; j++) {
                count[i][j][e] = 0;
                if (e == 0 && i == j) count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
                if (e > 1) {
                    for (int a = 0; a < nd; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e - 1];
                }
            }
        }
    }
    return count[u][v][k];
}
int cntwalks(int graph[][nd], int u, int v, int k) {
    if(k == 0 && u == v) return 1;
    if(k == 1 && graph[u][v]) return 1;
    if(k <= 0) return 0;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] == 1) cnt += cntwalks(graph, i, v, k - 1);
    }
    return cnt;
}
// Check if Tree A is mirror image of Tree B
int mirrorTree(int *arr, int *ray) {
    int n = 3, e = 2;
    vector <stack <int>> st; vector <queue <int>> qe;
    for(int i = 0; i <= n; i++) {
        st.push(stack <int> ());
        queue <int> q; qe.push(q);
    }
    for(int i = 0; i < 2 * e; i += 2) {
        st[arr[i]].push(arr[i + 1]);
        qe[ray[i]].push(ray[i + 1]);
    }
    for(int i = 1; i <= n; i++) {
        while(!st[i].empty() && !qe[i].empty()) {
            int x = st[i].top(); st[i].pop();
            int y = qe[i].top(); qe[i].pop();
            if(x != y) return 0;
        }
    }
    return 1;
}
int mirrorTree(int *u1, int *v1, int *u2, int *v2) {
    int n = sizeof(u1) / sizeof(u1[0]);
    unordered_map <int, stack <int>> mp;
    for(int i = 0; i < n; i++) mp[u1[i]].push_back(v1[i]);
    for(int i = 0; i < n; i++) {
        if(mp[u2[i]].top() != v2[i]) return 0;
        mp[u2[i]].pop();
    }
    return 1;
}
