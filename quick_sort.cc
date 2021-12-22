#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& nums)
{
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i != nums.size() - 1) {
            std::cout << ",";
        } else {
            std::cout << std::endl; 
        }
    }
}

bool compare(const std::vector<int>& nums, const std::vector<int>& cmp) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] != cmp[i]) {
            return false;
        }
    }
    return true;
}

class QuickSort {
public:
    void quickSort(std::vector<int>& nums)
    {
        if (nums.size() < 2) {
            return; 
        }

        return quickSort(nums, 0, nums.size() - 1);
    }

    void quickSort(std::vector<int>& nums, int l, int r)
    {
        if (l >= r) {
            return; 
        }

        srand((unsigned)time(0));
        int index = l + rand() % (r - l + 1);
        std::swap(nums[index], nums[l]);
        int p = partition(nums, l, r);
        quickSort(nums, l, p - 1);
        quickSort(nums, p + 1, r);
    }

    int partition(std::vector<int>& nums, int l , int r)
    {
        int p = nums[l];
        int i = l;
        int j = r;
        while (i < j) {
            while (nums[j] >= p && i < j) {
                j--;
            }
            while (nums[i] <= p && i < j) {
                i++; 
            }
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[l], nums[i]);
        return i;
    }
};


int main()
{
    int count = 10000;
    while (count--) {
        srand((unsigned)time(0));
        std::vector<int> nums;
        int length = rand() % 1000;
        for (size_t i = 0; i < length; ++i) {
            nums.push_back(rand() % 10);
        }
        QuickSort sort;
        sort.quickSort(nums);

        auto cmp = nums;
        std::sort(cmp.begin(), cmp.end());
        if (!compare(nums, cmp)) {
            std::cout << "********Fuck********" << std::endl;
            return 0;
        }
    }
    return 0;
}
