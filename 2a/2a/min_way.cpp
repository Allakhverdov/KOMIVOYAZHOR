//
//  min_way.cpp
//  2a
//
//  Created by Эдуард on 14.04.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//

#include "min_way.hpp"
#include <algorithm>
double MinWay::this_way (MatrixGraph& G, std::vector<int>permutation)           //по заданной последовательности вершин считаю длину пути
{
    double answer = 0;
    for(int i = 0; i < permutation.size() - 1; ++i)
    {
        answer += G.GetWeight(permutation[i], permutation[i + 1]);
    }
    answer += G.GetWeight(permutation[0], permutation[permutation.size() - 1]);
    return answer;
}

double MinWay::get_min_way(MatrixGraph &G)
{
    double inf = 1e9;
    MinWay Min;
    double answer = inf;
    int V = G.VCount();
    std::vector<int>permutation_i;
    permutation_i.resize(V);
    for(int i = 0; i < V ; ++i)                     //заполняем самую первую перестановку
    {
        permutation_i[i] = i;
    }
    do
    {
        double value = Min.this_way(G, permutation_i);                 //считаем длину нынешней перестановки
        if(answer > value)
        {
            answer = value;
        }
    } while ( std::next_permutation(permutation_i.begin(), permutation_i.end()));       //делаем новую перестановку
    return answer;
}
