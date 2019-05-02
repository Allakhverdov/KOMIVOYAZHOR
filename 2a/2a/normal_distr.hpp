//
//  normal_distr.hpp


//из рандомных данных, по нормальному распределению построим полный граф

#ifndef normal_distr_hpp
#define normal_distr_hpp
#include "ArcGraph.hpp"
#include "MatrixGraph.hpp"
#include<utility>
#include<random>
#include<vector>
#include<iostream>
#include <chrono>



struct norm_dist
{
    ArcGraph make_ArcGraph (int V);
    MatrixGraph make_MatrixGraph (int V);
private:
    std::vector<std::pair<double, double>> points (int N);
    double build_edge(int i_point, int j_point, std::vector<std::pair<double, double>>& coordinats);
};

#endif /* normal_distr_hpp */
