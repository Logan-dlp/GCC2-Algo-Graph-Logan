#ifndef _ALGO_HPP
#define _ALGO_HPP

namespace graph::algo {
    void ComputeRelatedComponents(int n, int m, int edges[][2], int comp[]);

    void ComputeRelatedComponentsOptimized(int n, int m, int edges[][2], int comp[]);

    // Kruskal
    typedef struct Point2D {int abs; int ord;} Point2D;

    void CreateRandomPoints(int n, Point2D points[]);
    void ComputeEdges(int n, int m, Point2D points[], int edges[][3]);

    void SortEdgesMatrix(int m, int edges[][3]);
    void Kruskal(int n, int m, int edges[][3], int tree[][2]);
}

#endif //_ALGO_HPP
