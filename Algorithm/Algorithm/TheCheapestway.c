#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define R 5
#define C 6
int Min(int x, int y, int z);
void main()
{
    int cost[R][C] = 
    { 
                       {3,4,1,2,8,6},
                       {6,1,8,2,7,4},
                       {5,9,3,9,9,5},
                       {8,4,1,3,2,6},
                       {3,7,2,8,6,4}
    };
    printf("Minimum Cost: %d ", minCost(cost, 4, 5));
}
// get the minimum cost from [0][0] to [m] [n]
int minCost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + Min(minCost(cost, m - 1, n - 1),
            minCost(cost, m - 1, n),
            minCost(cost, m, n - 1));
    // find the best path. (minimum cost path)
}
//  the function that finds the min value among three value.
int Min(int x, int y, int z)
{
    if (x < y) {
        if (x < z)
        {
            return x;
        }
        else
        {
            return z;
        }
    }
    else
    {
        if (y < z)
        {
            return y;
        }
        else
        {
            return z;

        }
    }

}
