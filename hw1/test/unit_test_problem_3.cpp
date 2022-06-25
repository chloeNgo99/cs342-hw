#include <vector>
#include "gtest/gtest.h"
#include "problem_3.h"

/*
 * homework
 */

// add your test using the following function
// you can add more of such test function

/**
 * This test check for 3 same followers
 * **/
TEST(problem_3, same_followers) {
    // add your work
    std::vector<Follower> followers = {
            Follower("Sam", 17),
            Follower("Lily", 22),
            Follower("Lisa", 21),
    };
    std::vector<Influencer> influencers = {
            Influencer("Alice", {
                followers[0],
                followers[1],
                followers[2]
            }),
            Influencer("Jannet", {
                    followers[0],
                    followers[1],
                    followers[2]
            }),
            Influencer("Chloe", {
                    followers[0],
                    followers[1],
                    followers[2]
            })
    };
    std::vector<Follower> expect = {
            followers[0],
            followers[1],
            followers[2]
    };
    ASSERT_EQ(expect, CustomerFinder::find_customer(influencers));
}

/**
 * This test check for 1 same followers
 * **/
TEST(problem_3, one_follower){
    std::vector<Follower> followers = {
            Follower("Sam", 17),
            Follower("Lily", 22),
            Follower("Lisa", 21),
    };
    std::vector<Influencer> influencers = {
            Influencer("Alice", {
                    followers[0],
                    followers[1],
                    followers[2]
            }),
            Influencer("Jannet", {
                    followers[1],
                    followers[2]
            }),
            Influencer("Chloe", {
                    followers[0],
                    followers[2]
            })
    };
    std::vector<Follower> expect = {
            followers[2]
    };
    ASSERT_EQ(expect, CustomerFinder::find_customer(influencers));
}

/**
 * This test check for no follower
 * **/
TEST(problem_3, no_follower){
    std::vector<Follower> followers = {
            Follower("Sam", 32),
            Follower("Lily", 22),
            Follower("Lisa", 21),
            Follower("Henry", 24),
            Follower("Jennie", 16),
            Follower("Jackson", 23),
            Follower("Kevin", 27),
    };
    std::vector<Influencer> influencers = {
            Influencer("Alice", {
                    followers[0],
                    followers[1],
                    followers[2]
            }),
            Influencer("Jannet", {
                    followers[4],
                    followers[5]
            }),
            Influencer("Chloe", {
                    followers[6],
                    followers[1]
            })
    };
    std::vector<Follower> expect = {
    };
    ASSERT_EQ(expect, CustomerFinder::find_customer(influencers));
}