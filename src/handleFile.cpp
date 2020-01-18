#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include "Dannon.hpp"

static bool fillDataSet(std::ifstream &file, std::vector<double> &data)
{
    std::istream_iterator<double> fileIt(file);
    std::back_insert_iterator<std::vector<double>> growDataIt(data);

    std::copy(fileIt, std::istream_iterator<double>(), growDataIt);
    if (data.size() == 0)
        return FAILURE;
    return SUCCESS;
}

static bool isPosNum(const std::string &str)
{
    std::string::const_iterator itStr =
    std::find_if(str.begin(), str.end(), [](const char c) { return !std::isdigit(c); });

    return itStr == str.end();
}

static bool isNegNum(const std::string &str)
{
    signed int number = stringToNumber<signed int>(str);

    return number < 0;
}

bool isNumDouble(const std::string &s)
{
    char *end = 0;
    double val = strtod(s.c_str(), &end);

    return end != s.c_str() && *end == '\0' && val != 12000;
}

static bool checkBadData(std::ifstream &file)
{
    std::istream_iterator<std::string> fileIt(file);

    while (fileIt != std::istream_iterator<std::string>()) {
        if (!isPosNum(*fileIt) and
        !isNegNum(*fileIt) and !isNumDouble(*fileIt))
            return FAILURE;
        fileIt++;
    }
    return SUCCESS;
}

bool handleFile(std::string fileParam, std::vector<double> &data)
{
    std::ifstream file;

    file.open(fileParam.c_str());
    if (file) {
        if (!checkBadData(file))
            return FAILURE;
        file.clear();
        file.seekg(0, std::ios::beg);
        if (!fillDataSet(file, data))
            return FAILURE;
    } else {
        std::cerr << "[ERROR] Can't open the file" << std::endl;
        return FAILURE;
    }
    file.close();
    return SUCCESS;
}
