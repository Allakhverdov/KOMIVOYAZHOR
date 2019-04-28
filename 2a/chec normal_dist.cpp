//#include <random>
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <map>
//
//using namespace std;
//
//void test(const double m, const double s, const int samples) {
//    
//    // uncomment to use a non-deterministic seed
//    //    random_device gen;
//    //    mt19937 gen(rd());
//    mt19937 gen(1701);
//    
//    normal_distribution<> distr(m, s);
//    
//    cout << endl;
//    cout << "min() == " << distr.min() << endl;
//    cout << "max() == " << distr.max() << endl;
//    cout << "m() == " << fixed << setw(11) << setprecision(10) << distr.mean() << endl;
//    cout << "s() == " << fixed << setw(11) << setprecision(10) << distr.stddev() << endl;
//    
//    // generate the distribution as a histogram
//    map<double, int> histogram;
//    for (int i = 0; i < samples; ++i) {
//        ++histogram[distr(gen)];
//    }
//    
//    // print results
//    cout << "Distribution for " << samples << " samples:" << endl;
//    int counter = 0;
//    for (const auto& elem : histogram) {
//        cout << fixed << setw(11) << ++counter << ": "
//        << setw(14) << setprecision(10) << elem.first << endl;
//    }
//    cout << endl;
//}
//
//int main()
//{
//    double m_dist = 1;
//    double s_dist = 1;
//    int samples = 10;
//    
//    cout << "Use CTRL-Z to bypass data entry and run using default values." << endl;
//    cout << "Enter a floating point value for the 'mean' distribution parameter: ";
//    cin >> m_dist;
//    cout << "Enter a floating point value for the 'stddev' distribution parameter (must be greater than zero): ";
//    cin >> s_dist;
//    cout << "Enter an integer value for the sample count: ";
//    cin >> samples;
//    
//    test(m_dist, s_dist, samples);
//}
