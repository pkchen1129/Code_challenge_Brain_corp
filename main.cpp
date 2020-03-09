// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <math.h>
// #include <random>

#include "Filter.hpp"

using namespace std;
int Randomdatanumgen(int a, int b){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(a, b);     
    int X = dis(gen); 
    return X;
}

vector<float> Randomdatagen(int N){
    vector<float> rawdata(N);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(DIS_MIN, DIS_MAX);   //uniform distribution between 0.03 and 50
    for (int i = 0; i < N; ++i) {
        rawdata[i] = dis(gen) ;
    }
    return rawdata;
}


void print_vec(vector<float> v){
    for (int i = 0; i < v.size(); i++) { 
        cout << setw(8) << v[i] << " " ; 
        // cout << setw(3);
        // cout << endl; 
    } 
}
int main(){
    cout << "Randomly Generate N, D? (y or n): ";
    char d;
    cin >> d;
    bool print;
    int N,D,iteration;
    if (int(d) == 121){
    //Randomly select
        N = Randomdatanumgen(MEAS_NUM_MIN, MEAS_NUM_MAX);//Random number of Measurements
        D = Randomdatanumgen(MED_NUM_MIN, MED_NUM_MAX);//Random number of previous scan D
        iteration = Randomdatanumgen(5 , 20);
        print = false;
    }
    else{
        //Manually input
        cout << "Input Dimension: ";
        cin >> N;
        cout << "Window_size: ";
        cin >> D;
        cout << "Number of iteration: ";
        cin >> iteration;
    }
    

    
    
//--------------------------------Range filter-------------------------------------
    //Output data
    cout << endl;
    cout << "--------------------------------Range filter------------------------------------------"<< endl;
    cout << endl;
    
    cout << "iteration = " << iteration << " || " << "# of measurement : " << N << endl;
    if(print){
        cout << "|Time |" << "          Input          " << "|          Output          |"<<   endl;
    }
    
    RangeFilter filter_ran(N);
    vector<float> output_range_filter(N,0);
    for (int i = 0 ; i < iteration ; ++i){
        
        //Rawdata every iteration
        vector<float> rawdata(N);
        rawdata = Randomdatagen(N);
        output_range_filter = filter_ran.range_filter(rawdata);
        if (print){
            cout << "|"<< setw(3) << i << "  ";
            cout << "|";
            print_vec(rawdata);
            cout << "|";
            print_vec(output_range_filter);
            cout << "|\n";
        }
        
        
    }

//--------------------------------Median filter-------------------------------------
    cout << endl;
    cout << "--------------------------------Median filter------------------------------------------"<< endl;
    cout << endl;    

    MedianFilter filter_med(N,D);
    cout << "|| iteration = " << iteration << " || " << "# of measurement : " << N << " || " << "Scan window size D : " << D << endl;
    if(print){
        cout << "|Time |" << "          Input          " << "|          Output          |"<<   endl;
    }
    
    for(int i = 0 ; i < iteration ; i++){
        vector<float> rawdata(N);
            vector<float> output_tempmedian_filter;
            rawdata = Randomdatagen(N);
            output_tempmedian_filter = filter_med.update_process(rawdata);

            //Printing data
            // cout << "| Time :" ; 
            if (print){
                cout << "|"<<setw(3) << i << "  ";
                cout << "|";
                print_vec(rawdata);
                cout << "|";
                print_vec(filter_med.median_list_out[i]);
                cout << "|\n";
            }
            
    }

//-------------------------------Check the correctness-----------------------------
    cout << endl;
    cout << "--------------------------------Self_check------------------------------------------"<< endl;
    cout << endl;
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < filter_ran.range_list_out.size(); i++) { 
        for (int j = 0; j < filter_ran.range_list_out[i].size(); j++) 
            if( filter_ran.range_list_out[i][j] > RANGE_MAX || filter_ran.range_list_out[i][j] < RANGE_MIN){
                count++;
            }
    } 
    
    if (count > 0 ){
        cout << "Range filter doen't work..." << endl;
    }
    else{
        cout << "Range filter works perfect!!!"<< endl;
    }

    // cout << filter_med.median_list.size() << endl;
    // cout << filter_med.median_list[0].size() << endl;
    // cout << filter_med.median_list_out.size() << endl;
    // cout << filter_med.median_list_out[0].size() << endl;

    // for (int i = 0; i < filter_med.median_list_out[0].size(); i++) { 
    //     vector<float> v;
    //     for (int j = 0; j < filter_med.median_list_out.size(); j++) {
    //         // v.push_back(filter_med.median_list[j][i]);
    //         // v.push_back(median_list[j][i]);
    //         // cout << v.size() << "___";
    //         // sort(v.begin(), v.end());
    //         if(v.size() % 2 > 0){                           //odd case
    //             if( filter_med.median_list_out[j][i] == v[v.size()/2]){
    //             }
    //             else{count2++;}
    //         }
    //         else{                                           //even case
                
    //             if( filter_med.median_list_out[j][i] == ((v[v.size()/2] + v[v.size()/2 - 1]) * 0.5) ){
    //                 count2++;
    //             }
    //             else{count2++;}
    //         }
    //     }
    // } 
    if (count2 > 0 ){
        cout << "Median filter doen't work..." << endl;
    }
    else{
        cout << "Median filter works perfect!!!"<< endl;
    }



    


}