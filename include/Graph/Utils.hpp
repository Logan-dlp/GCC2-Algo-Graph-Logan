#ifndef _UTILS_HPP
#define _UTILS_HPP

namespace graph::utils {
    void GenerateRandomGraph(int n, int m, int edges[][2]);
    void DisplayEdgeMatrix(int m, int edges[][2]);

    void DisplayComponentsMatrix(int n, int comp[]);

    void DisplayComponentsSizes(int n, int m, int comp[]);
}

#endif //_UTILS_HPP
