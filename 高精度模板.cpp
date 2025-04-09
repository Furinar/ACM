#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

// !------------------------------------

// TODO:高精度加法
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t)
        C.push_back(1);
    return C;
}

// TODO:高精度减法
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size();i++)
    {
        t = A[i] - t;
        if(i<B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if(t<0)
            t = 1;
        else
            t = 0;
    }
    return C;
}
// !------------------------------------

// ?------------------------------------
void println(vector<int> &T)
{
    for (int i = T.size() - 1; i >= 0; i--)
        printf("%d", T[i]);
}
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}
// ?------------------------------------

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    auto C = add(A, B);

    println(C);

    if (cmp(A, B))
    {
        auto D = sub(A, B);
        println(D);
    }
    else
    {
        auto D = sub(B, A);
        printf("-");
        println(D);
    }

    return 0;
}