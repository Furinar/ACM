#include <bits/stdc++.h>
using namespace std;

int N = 1e9 + 1;
int q[N], temp[N];

void quick_sort(int *q, int l, int r)
{
    if (l >= r)
        return;

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

void merge_sort(int *q, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int k = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];
    }
    while (i <= mid)
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];
}