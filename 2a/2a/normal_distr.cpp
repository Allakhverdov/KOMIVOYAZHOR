//
//  normal_distr.cpp
//  2a
//

#include"normal_distr.hpp"
std::vector<std::pair<double, double>> norm_dist::points (int N)
{
    int time = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()).time_since_epoch().count();
    std::mt19937 genX(time);
    std::mt19937 genY(time);
    std::normal_distribution<> distr(0,1);
    std::vector<std::pair<double, double>>coordinats;
    coordinats.resize(N);
    for(int i = 0; i < N; ++i)
    {
        coordinats[i].first = distr(genX);                  //генерируем рандомные координаты
        coordinats[i].second = distr(genY);
    }
    return coordinats;
}
double norm_dist::build_edge(int i_point, int j_point, std::vector<std::pair<double, double>>& coordinats)
{
    double i_x = coordinats[i_point].first;
    double i_y = coordinats[i_point].second;
    double j_x = coordinats[j_point].first;
    double j_y = coordinats[j_point].second;
    return sqrt((i_x - j_x)*(i_x - j_x) + (i_y - j_y)*(i_y - j_y));
}
ArcGraph norm_dist::make_ArcGraph (int V)                   //создаём на основе сгенерированных данных ArcGraph
{
    int E = V * (V - 1) / 2;
    ArcGraph G(0);
    
    norm_dist a;
    std::vector<std::pair<double, double>> Vert = a.points(V);
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            if(i != j)
            {
                double weight = a.build_edge(i, j, Vert);
                G.AddEdge(i, j, weight);
            }
        }
    }
    return G;
}

MatrixGraph norm_dist::make_MatrixGraph(int V)                      //создаём на основе сгенерированных данных MatrixGraph
{
    MatrixGraph G(V);
    norm_dist a;
    std::vector<std::pair<double, double>> Vert = a.points(V);
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            if(i != j)
            {
                double weight = a.build_edge(i, j, Vert);
                G.AddEdge(i, j, weight);
            }
        }
    }
    return G;
}
