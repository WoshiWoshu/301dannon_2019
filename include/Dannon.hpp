#pragma once

#include <sstream>

static const bool SUCCESS = true;
static const bool FAILURE = false;

template<typename T>
T stringToNumber(const std::string &str)
{
    std::istringstream strStream(str);
    T nb;

    return strStream >> nb ? nb : 0;
};

extern void selectionSort(std::vector<double> data);
extern void insertionSort(std::vector<double> data);
extern void bubbleSort(std::vector<double> data);
extern void quickSort(std::vector<double> data, int &nbCompQuick, int a, int b);

extern bool handleFile(std::string fileParam, std::vector<double> &data);
