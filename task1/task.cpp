#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>

uint8_t processLine(const std::string &line);

int main()
{
    std::ifstream inputFile("./input.txt");

    // Store each number from each line in vec
    std::vector<int> lineSum;

    // Process each line of file
    std::string line;
    while (std::getline(inputFile, line))
    {
        unsigned int num = processLine(line);
        lineSum.push_back(num);
    }
    inputFile.close();

    // Display total sum
    int totalSum = std::accumulate(lineSum.begin(), lineSum.end(), 0);
    std::cout << "Total Sum of all numbers: " << totalSum << std::endl;

    return 0;
}

uint8_t processLine(const std::string &line)
{
    uint8_t firstDigit, finalDigit = 0;
    uint16_t numConcat = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (isdigit(line[i]))
        {
            firstDigit = line[i];
            break;
        }
    }

    for (int i = line.size() - 1; i >= 0; i--)
    {
        if (isdigit(line[i]))
        {
            finalDigit = line[i];
            break;
        }
    }

    numConcat = static_cast<uint8_t>(firstDigit - '0') * 10 + static_cast<uint8_t>(finalDigit - '0');
    return numConcat;
}