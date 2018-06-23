#include <bits/stdc++.h>

using namespace std;
int a[100100];
struct node {
    int mxi;
    int mxj;
};
node st[400400];
void mg(int ci, int L, int R) {
    int a[] = {st[L].mxi, st[L].mxj, st[R].mxi, st[R].mxj};
    sort(a, a + 4);
    st[ci].mxi = a[3];
    st[ci].mxj = a[2];
}
node ans;
void mx(int ci) {
    int a[] = {ans.mxi, ans.mxj, st[ci].mxi, st[ci].mxj};
    sort(a, a + 4);
    ans.mxi = a[3];
    ans.mxj = a[2];
}
void build(int ci, int l, int r) {
    if (l > r) return;
    if (l == r) {
        st[ci] = {a[l], -1};
        //st[ci].mxi = a[l];
        //st[ci].mxj = -1;
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    build(L, l, m);
    build(R,m+1,r);
    mg(ci, L, R);
}
int I, X, Y;
void q(int ci, int l, int r) {
    if (l > r) return;
    if (l > Y || r < X) return;
    if (l >= X && r <= Y) {
        mx(ci);
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    q(L, l, m);
    q(R,m+1,r);
}
void update(int ci, int l, int r) {
    if (l > r) return;
    if (l > I || r < I) return;
    if (l == r) {
        a[l] = X;
        st[ci] = {a[l], -1};
        //st[ci].mxi = a[l];
        //st[ci].mxj = -1;
        return;
    }
    int m = (l + r) / 2;
    int L = 2 * ci + 1;
    int R = 2 * ci + 2;
    update(L, l, m);
    update(R,m+1,r);
    mg(ci, L, R);
}
/*char z[100100];
string in() {
    scanf("%s", z);
    return string(z);
}*/
int main() {
    /*string s;
    s = in();
    char *z = new char[100100];
    delete z;*/
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    build(0, 0, n - 1);
    int Q;
    scanf("%d", &Q);
    char tp;
    while (Q--) {
        scanf("%c", &tp);
        scanf("%c", &tp);
        if (tp == 'Q') {
            scanf("%d%d", &X, &Y);
            X--, Y--;
            ans = {-1, -1};
            q(0, 0, n - 1);
            printf("%d\n", ans.mxi + ans.mxj);
        }
        else {
            scanf("%d%d", &I, &X);
            I--;
            update(0, 0, n - 1);
        }
    }
    return 0;
}
