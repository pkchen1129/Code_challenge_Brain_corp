#include<iostream> 
#include<math.h>
#include<vector>
#include <chrono> 
#include "function.h"
using namespace std; 
using namespace std::chrono;


vector< vector<int> > read_matrix(){
    int row, column;
    cout << "Enter row number: ";
    cin >>  row;
    cout << "\nEnter column number: ";
    cin >>  column;
    cout << endl;
    vector<vector<int> > matrix;
	for (int i = 0 ; i < row ; ++i) {
		vector<int> roww;
        cout << i + 1 << "th row: ";
		for(int j = 0 ; j < column ; ++j){
			int value;
			cin >> value;
			roww.push_back(value);
		}
		matrix.push_back(roww);
	}
    return matrix;
}
void print_mat(vector<vector<int> > v){
    for (int i = 0; i < v.size(); i++) { 
        for (int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " "; 
        cout << endl; 
    } 
}

int main(){
    //Initialize v1//////////////////////////////////////////
    vector<vector<int> > v1;
    v1 = read_matrix();
    //Initialize v2//
    vector<vector<int> > v2;
    v2 = read_matrix();

    //count for naive matrix multiplication
    vector<vector<int> > v_naive;
    v_naive = naive_method( v1, v2);

    vector<vector<int> > v_permu;
    v_permu = loop_permutation( v1, v2);

    //count for transpose
    vector<vector<int> > v_trans;
    v_trans = transpose(v2);


    //////////Print////////
    cout << "v1: " << endl;
    print_mat(v1);
    cout << "v2: " << endl;
    print_mat(v2);

    //print v_naive
    cout << "v_naive: " << endl;
    print_mat(v_naive);
    cout << "v_permu: " << endl;
    print_mat(v_permu);
    
    //print transpose
    cout << "v1_transpose: " << endl;
    print_mat(v1);

}
