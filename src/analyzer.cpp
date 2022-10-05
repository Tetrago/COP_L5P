#include <iostream>
#include "StringData.h"
using namespace std;

int linear_search(const vector<string>& stringDataSet, string element)
{

    for (int i=0; i < stringDataSet.size(); i++)
    {
        if (stringDataSet[i] == element)
            return i;
    }

    return -1;
}

int binary_search(const vector<string>& stringDataSet, string element)
{

    int low = 0;
    int high = stringDataSet.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (stringDataSet[mid] == element)
            return mid;
        else if (element < stringDataSet[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;

}

int main() {
    vector<string> test = getStringData();

    cout << "Finding \"not_here\" using the Linear Search algorithm";

    long long start = systemTimeNanoseconds();
    int location = linear_search(test, "not_here");
    long long end = systemTimeNanoseconds();

    if (location == -1)
        cout << "not_here cannot be found, and it took "<< end - start<< "seconds.\n";
    else
        cout << "not_here was found at"<< location<< "and it took "<< end - start<< "seconds.\n";


    cout << "Finding \"not_here\" using the Binary Search algorithm";

    start = systemTimeNanoseconds();
    location = binary_search(test, "not_here");
    end = systemTimeNanoseconds();


    if (location == -1)
        cout << "not_here cannot be found, and it took" << end - start << "seconds.\n";
    else
        cout << "not_here was found at" << location << ", and it took"<< end - start<< "seconds.\n";


    cout << "Finding \"mzzzz\" using the Linear Search algorithm";

    start = systemTimeNanoseconds();
    location = linear_search(test, "mzzzz");
    end = systemTimeNanoseconds();

    if (location == -1)
        cout << "mzzzz cannot be found, and it took"<< end - start<< "seconds.\n";
    else
        cout << "mzzzz was found at"<< location<< "and it took"<< end - start<< "seconds.\n";

    cout << "Finding \"mzzzz\" using the Binary Search algorithm";

    start = systemTimeNanoseconds();
    location = binary_search(test, "mzzzz");
    end = systemTimeNanoseconds();


    if (location == -1)
        cout << "mzzzz cannot be found, and it took" << end - start << "seconds.\n";
    else
        cout << "mzzzz was found at" << location << ", and it took"<< end - start<< "seconds.\n";

    cout << "Finding \"aaaaa\" using the Linear Search algorithm";

    start = systemTimeNanoseconds();
    location = linear_search(test, "aaaaa");
    end = systemTimeNanoseconds();

    if (location == -1)
        cout << "\"aaaaa\" cannot be found, and it took"<< end - start<< "seconds.\n";
    else
        cout << "\"aaaaa\" was found at"<< location<< "and it took"<< end - start<< "seconds.\n";

    cout << "Finding \"aaaaa\" using the Binary Search algorithm";

    start = systemTimeNanoseconds();
    location = binary_search(test, "aaaaa");
    end = systemTimeNanoseconds();


    if (location == -1)
        cout << "\"aaaaa\" cannot be found, and it took" << end - start << "seconds.\n";
    else
        cout << "\"aaaaa\" was found at" << location << ", and it took"<< end - start<< "seconds.\n";
}
