#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */
long getWaysHelper(int n, int m, const std::vector<long>& c,
  std::vector<std::vector<long>>& memo_table)
{
    if (n == 0) {
        return 1;
    } else if (m < 0) {
        return 0;
    } else if (n < 0) {
        return 0;
    }

    if (memo_table[n][m] < 0) {
        memo_table[n][m] = getWaysHelper(n - c[m], m, c, memo_table) + getWaysHelper(n, m-1, c, memo_table);
    }

    return memo_table[n][m];
}

long getWays(int n, std::vector<long> c)
{
    std::vector<std::vector<long>> memo_table(n+1, std::vector<long>(c.size(), -1));

    for (std::size_t i = 0; i < c.size(); ++i) {
        memo_table[0][i] = 1;
    }

    return getWaysHelper(n, c.size()-1, c, memo_table);
}

int main()
{

    std::string first_multiple_input_temp;
    std::getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = std::stoi(first_multiple_input[0]);

    int m = std::stoi(first_multiple_input[1]);

    std::string c_temp_temp;
    std::getline(std::cin, c_temp_temp);

    std::vector<std::string> c_temp = split(rtrim(c_temp_temp));

    std::vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = std::stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c);

    std::cout << ways << "\n";

    return 0;
}

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
        s.begin(),
        std::find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

std::vector<std::string> split(const std::string &str) {
    std::vector<std::string> tokens;

    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

