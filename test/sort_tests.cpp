#include <limits>
#include <gtest/gtest.h>
#include <random>
#include <iostream>

#include "sorting_algs.hpp"

std::vector<int> generate_random_data(unsigned int size)
{
    std::uniform_int_distribution<int> distr(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::default_random_engine generator;

    std::vector<int> ret(size);
    std::generate(ret.begin(), ret.end(), [&](){ return distr(generator); });
    return ret;
}

bool is_sorted_asc(const std::vector<int>& in)
{
    for(unsigned int i=0; i<in.size()-1; i++)
    {
        if(in[i+1] < in[i])
        {
            return false;
        }
    }
    return true;
}

bool is_sorted_desc(const std::vector<int>& in)
{
    for(unsigned int i=0; i<in.size()-1; i++)
    {
        if(in[i+1] > in[i])
        {
            return false;
        }
    }
    return true;
}

TEST(sort_tests, insertion_sort)
{
    auto input = generate_random_data(100);
    insertion_sort(input);

    EXPECT_TRUE(is_sorted_asc(input));
}

TEST(sort_tests, insertion_sort_desc)
{
    auto input = generate_random_data(100);
    insertion_sort_desc(input);

    EXPECT_TRUE(is_sorted_desc(input));
}

TEST(sort_tests, insertion_sort_rec)
{
    auto input = generate_random_data(100);
    rec_insertion_sort(input, 0, 99);

    EXPECT_TRUE(is_sorted_asc(input));
}

TEST(sort_tests, selection_sort)
{
    auto input = generate_random_data(100);
    selection_sort(input);

    EXPECT_TRUE(is_sorted_asc(input));
}

TEST(sort_tests, bubble_sort)
{
    auto input = generate_random_data(100);
    bubble_sort(input);

    EXPECT_TRUE(is_sorted_asc(input));
}

TEST(sort_tests, merge_sort)
{
    auto input = generate_random_data(100);
    merge_sort(input);

    EXPECT_TRUE(is_sorted_asc(input));
}
