#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll st[400400];
ll lazy[400400];
void update(int ci, int l, int r, int x, int y, ll v) {
    if (l > r) return;
    if (lazy[ci] != 0) {
        st[ci] += ll(r - l + 1) * lazy[ci];
        if (l != r) {
            lazy[2 * ci + 1] += lazy[ci];
            lazy[2 * ci + 2] += lazy[ci];
        }
        lazy[ci] = 0;
    }
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        st[ci] += ll(r - l + 1) * v;
        if (l != r) {
            lazy[2 * ci + 1] += v;
            lazy[2 * ci + 2] += v;
        }
        return;
    }
    int m = (l + r) / 2;
    update(2 * ci + 1, l, m, x, y, v);
    update(2 * ci + 2,m+1,r, x, y, v);
    st[ci] = st[2 * ci + 1] + st[2 * ci + 2];
}
ll ans = 0;
void query(int ci, int l, int r, int x, int y) {
    if (l > r) return;
    if (lazy[ci] != 0) {
        st[ci] += ll(r - l + 1) * lazy[ci];
        if (l != r) {
            lazy[2 * ci + 1] += lazy[ci];
            lazy[2 * ci + 2] += lazy[ci];
        }
        lazy[ci] = 0;
    }
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        ans += st[ci];
        return;
    }
    int m = (l + r) / 2;
    query(2 * ci + 1, l, m, x, y);
    query(2 * ci + 2,m+1,r, x, y);
}
int main() {
    int T;
    cin >> T;
    int n, c;
    int t, p, q;
    ll v;
    while (T--) {
        cin >> n >> c;
        while (c--) {
            cin >> t;
            if (t) {
                cin >> p >> q;
                p--, q--;
                ans = 0;
                query(0, 0, n - 1, p, q);
                cout << ans << '\n';
            }
            else {
                cin >> p >> q >> v;
                p--, q--;
                update(0, 0, n - 1, p, q, v);
            }
        }
        memset(st, 0, sizeof st);
        memset(lazy, 0, sizeof lazy);
    }
    return 0;
}
