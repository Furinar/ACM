#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    while (m--)
    {
        int a, b;
        char op[2];
        scanf("%s %d %d", op, &a, &b);

        if (op == "M")
            p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}