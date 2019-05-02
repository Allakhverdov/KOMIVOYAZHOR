//
//  прогоняем тесты.cpp
//  2a
//
//  Created by Эдуард on 02.05.2019.
//  Copyright © 2019 Эдуард. All rights reserved.
//
#include "прогоняем тесты.hpp"

void tests::withdraw_tests() const
{
    std::ofstream fout;
    fout.open("/Users/eduard/Desktop/komi/KOMIVOYAZHOR/2a/2a/File.txt");
    for(int i = 5; i < 11; ++i)
    {
        std::cout<<"------------------------------"<< std::endl <<"Проводим замеры при V = "<< i
        << std::endl <<"------------------------------"<< std:: endl;
        fout <<"------------------------------"<< std::endl <<"Проводим замеры при V = "<< i
        << std::endl <<"------------------------------"<< std:: endl;;
        double avg_two = 0;
        double avg_one_point_five = 0;
        std::vector<double> two_aprox ;
        std::vector<double> one_point_five_aprox ;
        for(int j = 1; j < 11; ++j)
        {
            std::cout << "опыт номер:" << j << std::endl;
            fout << "опыт номер:" << j << std::endl;
            int V = i;
            norm_dist a;
            ArcGraph A_G(0);
            MatrixGraph M_G(0);
            A_G = a.make_ArcGraph(V);
            M_G = a.make_MatrixGraph(V);
            A_G.Cout_in_File(fout);
            MinWay b;
            double min_wey = b.get_min_way(M_G);                                    //считаем путь комивояжера
            double two_ap = Kruskal(A_G, V) * 2 / min_wey;                          //считаем 2-приближение
            double one_point_five_ap = Euler(A_G, M_G, V) / min_wey;                //считаем 1,5-приближение
            two_aprox.push_back(two_ap);
            one_point_five_aprox.push_back(one_point_five_ap);
            avg_two += two_ap;                                                      //считаем сумму времен
            avg_one_point_five += one_point_five_ap;                                //считаем сумму времен
            std::cout << " 2-aprox --> " << two_ap << std::endl;
            fout << " 2-aprox --> " << two_ap << std::endl;
            std::cout << " 1,5-aprox --> " << one_point_five_ap << std:: endl;
            fout << " 1,5-aprox --> " << one_point_five_ap << std:: endl;
        }
        avg_two = avg_two/10;                                                       //считаем среднее время
        avg_one_point_five = avg_one_point_five/10;                                 //считаем среднее время
        std::cout << "среднее 2-приближение:" << avg_two << std::endl;
        fout << "среднее 2-приближение:" << avg_two << std::endl;
        std::cout << "среднее 1.5-приближение:" << avg_one_point_five << std::endl;
        fout << "среднее 1.5-приближение:" << avg_one_point_five << std::endl;
        double delt_sum_two = 0;
        double delt_sum_one_point_five = 0;
        for(int r = 0; r < 10; ++r)
        {
            delt_sum_two += (two_aprox[r] - 1) * (two_aprox[r] - 1);
            delt_sum_one_point_five += (one_point_five_aprox[r] - 1) * (one_point_five_aprox[r] - 1);
        }
        delt_sum_two = sqrt(delt_sum_two / 10);                                    //считаем среднеквадратичное отклонение
        delt_sum_one_point_five = sqrt(delt_sum_one_point_five / 10);
        std::cout << "среднее квадратичное 2-отклонение:" << delt_sum_two << std::endl;
        fout << "среднее квадратичное 2-отклонение:" << delt_sum_two << std::endl;
        std::cout << "среднее квадратичное 1.5-отклонение:" << delt_sum_one_point_five << std::endl;
        fout << "среднее квадратичное 1.5-отклонение:" << delt_sum_one_point_five << std::endl;
    }
    fout.close();
}
