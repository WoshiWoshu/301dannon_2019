#include <iostream>
#include <vector>

void swapData(std::vector<double> &data, int i, int j)
{
    double tmpData(0.0);

    tmpData = data.at(i);
    data.at(i) = data.at(j);
    data.at(j) = tmpData;
}

void selectionSort(std::vector<double> data)
{
    std::size_t nbComb(1);
    long sizeDataSet(data.size());
    int min(0);

    for (int i = 1; i < sizeDataSet - 1; ++i) {
        min = i;
        nbComb++;
        for (int j = i + 1; j < sizeDataSet; ++j) {
            if (data.at(j) < data.at(min))
                min = j;
            nbComb++;
        }
        if (min != i)
            swapData(data, min, i);
    }
    std::cout << "Selection sort: " << nbComb << " comparisons" << std::endl;
}

void insertionSort(std::vector<double> data)
{
    long sizeDataSet(data.size());
    std::size_t nbComb(0);
    double tmpData(0.0);
    int j(0);

    for (int i = 1; i < sizeDataSet; i++) {
        tmpData = data.at(i);
        nbComb++;
        for (j = i; j > 0 and data.at(j - 1) > tmpData; j--, nbComb++)
            data.at(j) = data.at(j - 1);
        data.at(j) = tmpData;
    }
    std::cout << "Insertion sort: " << nbComb << " comparisons" << std::endl;
}

void bubbleSort(std::vector<double> data)
{
    long sizeDataSet(data.size());
    std::size_t nbComb(0);

    for (std::size_t i = sizeDataSet - 1; i > 0; --i)
        for (std::size_t j = 0; j < i; ++j) {
            if (data.at(j) > data.at(j + 1))
                swapData(data, j, j + 1);
            nbComb++;
        }
    std::cout << "Bubble sort: " << nbComb << " comparisons" << std::endl;
}

static int partition(std::vector<double> data, int &nbCompQuick, int a, int b, int rotate)
{
    int tmpA(a);
    int i(a);

    nbCompQuick++;
    swapData(data, rotate, b);
    while (i < b - 1) {
        nbCompQuick++;
        if (data.at(i) <= data.at(b)) {
            swapData(data, i, tmpA);
            tmpA++;
        }
        i++;
    }
    swapData(data, b, tmpA);
    return tmpA;
}

void quickSort(std::vector<double> data, int &nbCompQuick, int a, int b)
{
    int rotate(0);

    if (a < b) {
        rotate = (b - a) / 2;
        rotate = partition(data, nbCompQuick, a, b, rotate);
        quickSort(data, nbCompQuick, a, rotate - 1);
        quickSort(data, nbCompQuick, rotate + 1, b);
    }
}
