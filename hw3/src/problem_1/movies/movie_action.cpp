#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
    int base_fee = late_fee_per_day_in_dollar * num_of_days_past_due;
    int fee = (num_of_days_past_due >= 5) ? 2 * base_fee : base_fee;
    return mercy_rule_apply() ? 0 : fee;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}