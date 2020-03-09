#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <random>
#include <iomanip>
/*
This is the class structure of temporal median filter and range filter. 
You could change the RANGE_MIN and RANGE_MAX for the range filter
*/

//for range filter(Could be set manually)
#define RANGE_MIN 0.03
#define RANGE_MAX 20 //
//Measure distance range(provided by document)
#define DIS_MIN 0.03
#define DIS_MAX 50
//Measure number range(provided by document)
#define MEAS_NUM_MIN 200
#define MEAS_NUM_MAX 1000
//Median filter num range(If inputing manually then it's useless)
#define MED_NUM_MIN 5
#define MED_NUM_MAX 10


using namespace std;

//-------------------------Range Filter---------------------------------//
class RangeFilter{
private:
    int filter_length;
public:
    RangeFilter(int _filter_length) 
        : filter_length(_filter_length)
    {}
    vector<float> range_filter(vector<float> input);
    vector<vector<float>> range_list_out;
};
vector<float> RangeFilter::range_filter(vector<float> input){
    for (auto &scan : input){
        if( scan < RANGE_MIN){
            scan = RANGE_MIN;
        }
        else if( scan > RANGE_MAX){
            scan = RANGE_MAX;
        }
    }
    range_list_out.push_back(input);
    return input;
    
};

//-------------------------Median Filter---------------------------------//

class MedianFilter{
private:
    int size;
    int filter_length;
    
public:
    MedianFilter(int _filter_length, int _size) 
        : filter_length(_filter_length)
        , size(_size)
    {}
    vector<float> update_process(vector<float> new_data); //process update for temporal median filter
    void pop_front(vector<vector<float>> &v);
    vector<vector<float>> median_list;
    vector<vector<float>> median_list_out;
};

//pop_front for vector
void MedianFilter::pop_front(vector<vector<float>> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
//main update process for temporal median filter
vector<float> MedianFilter::update_process(vector<float> new_data){
    vector<float> out;
    // putting same position of data into vector and sort

    median_list.push_back(new_data);
    //When bigger than window_size
    if(median_list.size() > size){
        pop_front(median_list);
    }

    for(int i = 0 ; i < median_list[0].size(); i++){
        vector<float> v;
        for (int j = 0 ; j < median_list.size(); j++){
            v.push_back(median_list[j][i]);
        }
        //sort v
        sort(v.begin(), v.end());
        //Get the median and put in "out"
        if(v.size() % 2 > 0){                           //odd case
            out.push_back(v[v.size()/2 ]);
        }
        else{                                           //even case
            out.push_back((v[v.size()/2] + v[v.size()/2 - 1]) * 0.5);
        }
    }
    median_list_out.push_back(out);
    return out;
}
