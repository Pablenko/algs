#include <functional>
#include <vector>

void insertion_sort(std::vector<int>& in)
{
    for(unsigned int j=1; j<in.size(); j++)
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

void insertion_sort_desc(std::vector<int>& in)
{
    for(unsigned int j=1; j<in.size(); j++)
    {
        int key = in[j];
        int i = j - 1;
        while(i>=0 && in[i] < key)
        {
            in[i+1] = in[i];
            i--;
        }
        in[i+1] = key;
    }
}

void selection_sort(std::vector<int>& in)
{
    for(unsigned int i=0; i<in.size()-1; i++)
    {
        int smallest = in[i];
        for(unsigned int j=i+1; j<in.size(); j++)
        {
            if(in[j] < smallest)
            {
                smallest = in[j];
            }
        }
        in[i] = smallest;
    }
}

void bubble_sort(std::vector<int>& in)
{
    for(unsigned int i=1; i<in.size(); i++)
    {
        for(unsigned int j=in.size()-1; j>0; j--)
        {
            if(in[j] < in[j-1])
            {
                unsigned int tmp = in[j];
                in[j] = in[j-1];
                in[j-1] = tmp;
            }
        }
    }
}

void merge(std::vector<int>& in, unsigned int beg, unsigned int mid, unsigned int end)
{
    unsigned int n1 = mid - beg + 1;
    unsigned int n2 = end - mid;
    const unsigned int sentinel = std::numeric_limits<int>::max();

    std::vector<int> l(n1+1);
    std::vector<int> r(n2+1);

    for(unsigned int i=0; i<n1; i++)
    {
        l[i] = in[beg + i];
    }

    for(unsigned int i=0; i<n2; i++)
    {
        r[i] = in[mid + 1 + i];
    }

    l[n1] = sentinel;
    r[n2] = sentinel;

    unsigned int i = 0, j = 0;

    for(unsigned int k = beg; k < end; k++)
    {
        if(l[i] < r[j])
        {
            in[k] = l[i];
            i++;
        }
        else
        {
            in[k] = r[j];
            j++;
        }
    }
}

void merge_sort_helper(std::vector<int>& in, unsigned int beg, unsigned int end)
{
   if(beg < end)
   {
        unsigned int pivot = (beg + end) / 2;
        merge_sort_helper(in, beg, pivot);
        merge_sort_helper(in, pivot+1, end);
        merge(in, beg, pivot, end);
    }
}

void merge_sort(std::vector<int>& in)
{
    return merge_sort_helper(in, 0, in.size()-1);
}