#include <iostream>
#include <regex>
#include <string>

int main()
{
    {
        // 判断是否匹配
        std::string fnames[] = {"foo.txt", "bar.txt", "a0.txt", "AAA.txt"};
        std::regex pattern("[a-z]+\\.txt");

        for (const auto &fname : fnames)
        {
            std::cout << fname << ": " << std::regex_match(fname, pattern) << std::endl;
        }
    }

    {
        // 获取匹配结果
        std::string fnames[] = {"foo.txt", "bar.txt", "a0.txt", "AAA.txt"};
        std::regex pattern("([a-z]+)\\.txt");
        std::smatch result;
        for (const auto &fname : fnames)
        {
            if (std::regex_match(fname, result, pattern))
            {
                if (result.size() == 2)
                {
                    std::cout << "sub match[0]: " << result[0].str() << std::endl; // the first element of std::smatch matches the entire string
                    std::cout << "sub mathc[1]: " << result[1].str() << std::endl; // the second element of std::smatch matches the first expression with brackets
                }
            }
        }
    }
    {
        // 匹配手机号
        std::string fnames[] = {"13402126591", "63882159", "132456", "03402126591"};
        std::regex pattern;
        // pattern.assign("1[0-9]{10}");
        pattern.assign("/^1(3\\d|4[5-9]|5[0-35-9]|6[2567]|7[0-8]|8\\d|9[0-35-9])\\d{8}$/");
        for (const auto &fname : fnames)
        {
            std::cout << fname << ": " << std::regex_match(fname, pattern) << std::endl;
        }
    }
    return 0;
}