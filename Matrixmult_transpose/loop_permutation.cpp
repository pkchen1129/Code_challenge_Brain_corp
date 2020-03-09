#include "function.h"
vector< vector<int> > loop_permutation(vector<vector<int> > v1, vector<vector<int> > v2){
    auto start_trans = std::chrono::system_clock::now();
    int n = v1.size();
    int m = v1[0].size();
    int z = v2.size();
    int p = v2[0].size();
    if (m != z){
        cout << "multiplication dimension error..."; 
        return{};
    }
    vector<vector<int> > v( n , vector<int> (p, 0)); 
    int i,j,k;
    for (int i = 0 ; i < n ; i++ ){
        for (int k = 0 ; k < m ; k++){
            int sum = 0;
            for (int j = 0 ; j < p ; j++){
                sum += v1[i][k] * v2[k][j];
                v[i][j] = sum;
            }
        }
    }
    auto stop_trans = std::chrono::system_clock::now();
    std::chrono::duration<double> t1 = stop_trans - start_trans;
    cout << "Time duration of loop_permutation matrix multiplication: " << t1.count() << "s" << endl;
    return v;
}