#include <iostream>
#include <cstdlib>

#include "../include/Graph/Utils.hpp"
#include "../include/Graph/Algo.hpp"

namespace GraphUtils = graph::utils;
namespace GraphAlgo = graph::algo;

int main() {
    std::cout << "Practical exercices: connected components" << std::endl;

    int n, m; //Nombre de sommets et d'arêtes

    std::cout << "Entrer le nombre de sommets: ";
    std::cin >> n;
    std::cout << "Entrer le nombre d'arêtes: ";
    std::cin >> m;

    int edges[m][2];
    int comp[n];

    GraphUtils::GenerateRandomGraph(n, m, edges);
    GraphUtils::DisplayEdgeMatrix(m, edges);

    GraphAlgo::ComputeRelatedComponents(n, m, edges, comp);
    GraphUtils::DisplayComponentsMatrix(n, comp);

    GraphUtils::DisplayComponentsSizes(n, m, comp);

    return 0;
}