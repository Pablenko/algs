#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

void insertion_sort(std::vector<int>& in)
{
    for(int j=1; j<in.size(); j++)
    {
        int key = in[j];
        int i = j-1;
        while(i>=0 && in[i] > key)
        {
            in[i+1] = in[i];
            i--;
        }
        in[i+1] = key;
    }
}

int main()
{
    std::vector<int> input = {-9, 2, -4, 6, 1, 1, 5, 0 -1, 11, -200, 5};
    std::vector<int> expected_input = input;
    std::sort(expected_input.begin(), expected_input.end());

    insertion_sort(input);

    std::cout << "EXPECTED: \n";
    std::copy(expected_input.begin(), expected_input.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout <<std::endl;

    std::cout << "ACTUAL: \n";
    std::copy(input.begin(), input.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout <<std::endl;

    for(int i=0; i<input.size(); i++)
    {
        assert(input[i] == expected_input[i]);
    }
}