#include <cctype>
#include <chrono>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

uint8_t processLine(const std::string &line);

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream inputFile("./input.txt");

    // Store each number from each line in vec
    std::vector<int> rowNumbers;

    // Process each line of file
    std::string line;
    while (std::getline(inputFile, line))
    {
        unsigned int num = processLine(line);
        rowNumbers.push_back(num);
    }
    inputFile.close();

    // Display total sum
    int totalSum = std::accumulate(rowNumbers.begin(), rowNumbers.end(), 0);
    std::cout << "\nTotal Sum of all numbers: " << totalSum << std::endl;

    // Display exec time
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Total duration: " << duration.count() << " microseconds" << std::endl;

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