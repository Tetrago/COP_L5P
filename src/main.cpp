#include "StringData.h"

#include <iostream>
#include <iomanip>
#include <chrono>

inline auto now()
{
    return std::chrono::system_clock::now();
}

int linear_search(const std::vector<std::string>& data, const std::string& element)
{
    for(int i = 0; i < data.size(); ++i)
    {
        if(data[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(const std::vector<std::string>& data, const std::string& element)
{
    uint32_t begin = 0;
    uint32_t end = data.size();

    while(begin != end)
    {
        uint32_t middle = (end - begin) / 2 + begin;

        if(data[middle] > element)
        {
            end = middle;
        }
        else if(data[middle] < element)
        {
            begin = middle + 1;
        }
        else
        {
            return static_cast<int>(middle);
        }
    }

    return -1;
}

void search(const std::vector<std::string>& data, const std::string& query)
{
    std::cout << "=================================\nLinearly searching \"" << query << "\"..." << std::endl;

    auto start = now();
    int index = linear_search(data, query);
    std::chrono::duration<double> duration = now() - start;

    std::cout << "Found element at index " << index << "\nTook " << std::fixed << std::setprecision(12) << duration.count() << " seconds." << std::endl;

    std::cout << "---------------------------------\nBinary searching \"" << query << "\"..." << std::endl;

    start = now();
    index = binary_search(data, query);
    duration = now() - start;

    std::cout << "Found element at index " << index << "\nTook " << std::fixed << std::setprecision(12) << duration.count() << " seconds." << std::endl;

    std::cout << "=================================" << std::endl;
}

int main()
{
    const std::vector<std::string> data = getStringData();

    search(data, "not_here");
    search(data, "mzzzz");
    search(data, "aaaaa");
}
