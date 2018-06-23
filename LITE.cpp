#include <bits/stdc++.h>

using namespace std;
int I, J;
int st[400400];
int lazy[400400];
int ans = 0;
void update(int ci, int l, int r) {
    if (l > r) return;
    if (lazy[ci]) {
        st[ci] = (r - l + 1) - st[ci];
        if (l != r) {
            lazy[2 * ci + 1] = 1 - lazy[2 * ci + 1];
            lazy[2 * ci + 2] = 1 - lazy[2 * ci + 2];
        }
        lazy[ci] = 0;
    }
    if (l > J || r < I) return;
    if (l >= I && r <= J) {
        st[ci] = (r - l + 1) - st[ci];
        if (l != r) {
            lazy[2 * ci + 1] = 1 - lazy[2 * ci + 1];
            lazy[2 * ci + 2] = 1 - lazy[2 * ci + 2];
        }
        return;
    }
    int m = (l + r) / 2;
    update(2 * ci + 1, l, m);
    update(2 * ci + 2,m+1,r);
    st[ci] = st[2 * ci + 1] + st[2 * ci + 2];
}
void q(int ci, int l, int r) {
    if (l > r) return;
    if (lazy[ci]) {
        st[ci] = (r - l + 1) - st[ci];
        if (l != r) {
            lazy[2 * ci + 1] = 1 - lazy[2 * ci + 1];
            lazy[2 * ci + 2] = 1 - lazy[2 * ci + 2];
        }
        lazy[ci] = 0;
    }
    if (l > J || r < I) return;
    if (l >= I && r <= J) {
        ans += st[ci];
        return;
    }
    int m = (l + r) / 2;
    q(2 * ci + 1, l, m);
    q(2 * ci + 2,m+1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int op;
    while (m--) {
        cin >> op >> I >> J;
        I--, J--;
        if (op) {
            ans = 0;
            q(0, 0, n - 1);
            cout << ans << '\n';
        }
        else update(0, 0, n - 1);
    }
    return 0;
}
