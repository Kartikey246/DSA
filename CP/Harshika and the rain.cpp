#include "bits/stdc++.h"
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
*/

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;
const int mod = 1e9+7;

vector<vector<int>> adj;
vector<int> L;
vector<int> dist;
ll X;

void dfs(int u, int p = -1) {
    for (int v : adj[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
    if (sz(adj[u]) == 1 and u != 0) {
        X++;
        L[dist[u]]++;
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    X = 0;
    adj.clear(); L.clear(); dist.clear();
    adj.resize(n); L.resize(n); dist.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> a(m+1);
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    dfs(0);
    ll D = n-1;
    while (L[D] == 0)
        --D;
    vector<ll> R(D+1);
    ll cursum = 0;
    for (int i = 1; i <= D; ++i) {
        R[i] = R[i-1] + (cursum + L[i-1]);
        cursum += L[i-1];
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ll Y = a[i] - a[i-1];
        if (Y <= D)
            ans += R[Y];
        else
            ans += R[D] + (Y - D) * X;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) solve(i);
    return 0;
}
