#include <bits/stdc++.h>

using namespace std;
int a[100100];
int st[400400];
void build(int ci, int l, int r) {
    if (l > r) return;
    if (l == r) {
        st[ci] = a[l];
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    build(L, l, m);
    build(R, m + 1, r);
    st[ci] = st[L] + st[R];
}
void print(int ci, int l, int r) {
    if (l > r) return;
    if (l == r) {
        cout << ci << ' ' << l << ' ' << r << ' ' << st[ci] << '\n';
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    print(L, l, m);
    print(R, m + 1, r);
    cout << ci << ' ' << l << ' ' << r << ' ';
    cout << st[ci] << '\n';
}
int ans = 0;
void q(int ci, int l, int r, int x, int y) {
    if (l > r) return;
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        ans += st[ci];
        return;
    }
    int m = (l + r) / 2;
    q(2 * ci + 1, l, m, x, y);
    q(2 * ci + 2,m+1,r, x, y);
}
void update(int ci, int l, int r, int i, int x) {
    if (l > r) return;
    if (l > i || r < i) return;
    if (l == r) {
        a[l] = x; //neglected
        st[ci] = x;
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    update(L, l, m, i, x);
    update(R, m + 1, r, i, x);
    st[ci] = st[L] + st[R];
}
int I, X;
void updatE(int ci, int l, int r) {
    if (l > r) return;
    if (l > I || r < I) return;
    if (l == r) {
        a[l] = X; //neglected
        st[ci] = X;
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    updatE(L, l, m);
    updatE(R, m + 1, r);
    st[ci] = st[L] + st[R];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, 0, n - 1);
    //print(0, 0, n - 1);
    int Q;
    cin >> Q;
    int ti, li, ri;
    int ii, xi;
    while (Q--) {
        cin >> ti;
        if (ti == 0) {
            cin >> li >> ri;
            ans = 0;
            q(0, 0, n - 1, li, ri);
            cout << ans << '\n';
        }
        else {
            cin >> ii >> xi;
            I = ii, X = xi;
            update(0, 0, n - 1, ii, xi);
        }
    }
    return 0;
}
