#include "stat_calculator.h"

float StatCalculator::mean(const List<float> &data) {
    /*
     * TODO: homework
     * mean = sum of all number in the data set divided by the data size
     */
    int size = data.size();
    float sum = 0;
    for(int i = 0; i < size; i++){
        sum += data[i];
    }
    //if sum == 0, return 0
    return sum == 0 ? 0 : sum/size;
}

/*
 * based on https://www.calculatorsoup.com/calculators/statistics/percentile-calculator.php
 */
void StatCalculator::percentiles(List<float> &data,
                                 int percentile_target_step,
                                 Map<int, float> &result_map) {
    /*
     * TODO: homework
     */
    //sort data set
    sort(data);

    float percentage = (float) percentile_target_step;
    float rank = ((percentage/100) * (data.size()-1))+1;
    //if rank is an integer
    int rankInt = (int) rank;
    if(rank - rankInt == 0){
        result_map.put(percentile_target_step, rank);
    }else{
        float ri = rank;
        int r = (int) rank;
        float rf = ri - r;
        float p = data[r-1] + rf * (data[r]-data[r-1]);
        result_map.put(percentile_target_step,p);
    }

}

void StatCalculator::sort(List<float> &data) {
    size_t length = data.size();
    if (length < 2) {
        return;
    }
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data, j, j + 1);
            }
        }
    }
}

void StatCalculator::swap(List<float> &data, size_t i, size_t j) {
    float tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}