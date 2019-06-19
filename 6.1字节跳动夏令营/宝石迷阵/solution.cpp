#include <bitset/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int N = 200010, M = N * 2, P = 131;

int val[ N ], ans[ N ];
// idx: 边的编号
// h[i]: 第i个点为端点连接的最后一条边的编号
// e[idx]: 边idx的终点
// ne[idx]: 这条边之前的有相同起点的边
int h[ N ], e[ M ], ne[ M ], ch[ M ], idx;
int n, q;

// 数组模拟单链表实现邻接表
void add( int a, int b, int c )
{
    e[ idx ] = b;
    ch[ idx ] = c;
    ne[ idx ] = h[ a ];
    h[ a ] = idx ++;
}

unordered_map< ULL, int > dfs( int u,int father )
{
    unordered_map< ULL, int > heap;
    heap[ 0 ] = val[ u ];
    ans[ u ] = 0;
    for( int i = h[ u ]; ~i; i = ne[ i ] )
    {
        if( e[ i ] == father ) continue;
        auto S = dfs( e[ i ], u );
        for( auto x: S ) heap[ x.first * P + ch[ i ] ] += x.second;
    }
    for( auto x: heap ) ans[ u ] = max( ans[ u ], x.second );
    return heap;
}

int main()
{
    scanf( "%d %d", &n, &q );
    memset( h, -1, sizeof( h ) );
    idx = 0;
    for( int i = 1; i <= n; i ++ ) scanf( "%d", &val[ i ] );
    for( int i = 1; i < n; i ++ )
    {
        int a, b;
        char c[ 2 ];
        scanf( "%d%d%s", &a, &b, c );
        add( a, b, *c );
        add( b, a, *c );
    }
    dfs( 1, - 1 );

    for( int i = 1; i <= q; i ++ )
    {
        int x;
        scanf( "%d", &x );
        printf( "%d\n", ans[ x ] );
    }
    return 0;
}

