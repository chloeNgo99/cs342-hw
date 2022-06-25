#include "problem_1.h"

/*
 *When I was a kid, I had a little piggy bank where I can save my pocket money every day,
 * and I would break it whenever it was full or at the end of every year.
 * Growing up, I get introduced to the concept of compound interest, but I was not very
 * interested in learning the mechanism behind it. Though, I couldn’t imagine that one that
 * I would have to write an algorithm that computes the compound interest. Since it brought to
 * my attention how much money I can save with just a little investment.
 * This encouraged me to start investing early since compound interest works best over a
 * long period of time. Spent money less on unnecessary things, use it as a daily or monthly
 * contribution and avoid having an outstanding debt for the rest of my career life.
 */


CompoundResult
Compounder::calculate_without_roundOff(float init_deposit, float monthly_contribution, float length_in_year,
                                       float rate_in_percentage) {
    CompoundResult result;

    /*
     * convert rate_in_percentage follow this formula :
     * rate = 1 + rate_in_percentage/100
     * convert monthly_contribute into yearly:
     * monthly_contribute * 12 months
     * result.invested = monthly contributed in terms of year * length of year +
     * initial investment
     * then use while loop to calculate the result.accumulated through each year
     */
    result.invested = 0;
    result.accumulated = 0;

    if (init_deposit <= 0 || monthly_contribution <= 0 || length_in_year <= 0) {
        return result;
    }

    result.accumulated = init_deposit;
    rate_in_percentage = 1+rate_in_percentage/100;
    monthly_contribution *= 12;

    int year = (int) length_in_year, count = 0;
    float annual = 0;
    result.invested = length_in_year * monthly_contribution + init_deposit;
    while(count < year){
        annual = result.accumulated * rate_in_percentage;
        result.accumulated = annual + monthly_contribution;
        count++;
    }


    return result;
}

CompoundResult
Compounder::calculate(float init_deposit, float monthly_contribution, float length_in_year, float rate_in_percentage) {
    CompoundResult result;

    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        length_in_year <= 0) {
        return result;
    }

    result = calculate_without_roundOff(init_deposit, monthly_contribution, length_in_year, rate_in_percentage);

    result.accumulated = roundOff(result.accumulated);
    return result;
}

// https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
float Compounder::roundOff(float value) {
    int ret = (int) (value * 100 + .5);
    float r = (float) ret / 100;
    return r;
}

CompoundResult
Compounder::calculate(float init_deposit, float monthly_contribution, std::vector<float> interest_rates) {
    CompoundResult result;
    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        interest_rates.empty()) {
        return result;
    }

    result.invested = 0;
    result.accumulated = 0;
    float invested = init_deposit;

    // std::size_t in the loop to prevent comparison warning
    // https://stackoverflow.com/questions/3660901/a-warning-comparison-between-signed-and-unsigned-integer-expressions
    for (std::size_t i = 0; i < interest_rates.size(); i++) {
        float rate = interest_rates[i];
        float deposit = (i == 0) ? init_deposit : result.accumulated;
        result = calculate_without_roundOff(deposit, monthly_contribution, 1, rate);
        invested += monthly_contribution * 12;
    }

    result.invested = invested;
    result.accumulated = roundOff(result.accumulated);

    return result;
}