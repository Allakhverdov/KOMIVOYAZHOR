
//  struct_Edge.hpp


//эта структура - просто представление ребра

#ifndef struct_Edge_hpp
#define struct_Edge_hpp

struct Edge
{
    Edge(int from, int to, double weight) : from(from), to(to), weight(weight){}
    Edge(){}
    int from = 0;
    int to = 0;
    double weight = 0;
    bool operator <(const Edge& a) const;
};


#endif /* struct_Edge_hpp */
