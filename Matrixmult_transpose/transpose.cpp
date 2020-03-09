#include "function.h"
vector< vector<int> > transpose(vector<vector<int> > v1){
    auto start_trans = std::chrono::system_clock::now();
    int n = v1.size();
    int m = v1[0].size();
    vector<vector<int> > v( m , vector<int> (n, 0)); 
    int i,j;
    for (int i = 0 ; i < m ; i++ ){
        for (int j = 0 ; j < n ; j++){
            v[i][j] = v1[j][i];
        }
    }
    auto stop_trans = std::chrono::system_clock::now();
    std::chrono::duration<double> t1 = stop_trans - start_trans;
    cout << "Time duration of transpose multiplication: " << t1.count() << "s" << endl;
    return v;
}