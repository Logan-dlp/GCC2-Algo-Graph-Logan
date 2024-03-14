#include <iostream>
#include <cstdlib>

void GenerateRandomGraph(int n, int m, int edges[][2]);

int main() {
    std::cout << "Practical exercices: connected components" << std::endl;

    int n, m; //Nombre de sommets et d'arêtes

    std::cout << "Entrer le nombre de sommets: ";
    std::cin >> n;
    std::cout << "Entrer le nombre d'arêtes: ";
    std::cin >> m;

    int edges[m][2];
    int comp[n];

    return 0;
}

void GenerateRandomGraph(int n, int m, int edges[][2]) {
    for (int i = 0; i < m; ++i) {
        std::srand(time(nullptr));

        edges[i][0] = std::rand() % n;
        edges[i][1] = std::rand() % n;
    }
}