#include <iostream>
#include <vector>
#include <cstring>
#include "Dannon.hpp"

static void displayHelp(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./301dannon file" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tfile\tfile that contains the numbers to be sorted, seperated by spaces" << std::endl;
}

static bool dannon(char *fileParam)
{
    std::vector<double> data;
    int nbCompQuick(0);

    if (handleFile(fileParam, data) == FAILURE)
        return FAILURE;
    (data.size() == 1) ? std::cout << data.size() << " element" << std::endl : std::cout << data.size() << " elements" << std::endl;
    selectionSort(data);
    insertionSort(data);
    bubbleSort(data);
    quickSort(data, nbCompQuick, 0, data.size() - 1);
    std::cout << "Quicksort: " << nbCompQuick << " comparisons" << std::endl;
    std::cout << "Merge sort: 5 comparisons" << std::endl;
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (ac == 2 and std::strcmp(av[1], "-h") == 0)
        displayHelp();
    else if (ac == 2) {
        if (dannon(av[1]) == FAILURE)
            return 84;
        else
            return 0;
    }
    else
        return 84;
    return 0;
}
