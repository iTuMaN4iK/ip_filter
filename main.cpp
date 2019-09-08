#include "lib.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
using ip_pool_type =std::vector<std::vector<std::string> >;
using ip_type = std::vector<std::string> ;
ip_type split(const std::string &str, char d)
{
    ip_type r;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void printIpPool (const ip_pool_type & v){
    for(ip_pool_type::const_iterator ip = v.cbegin(); ip != v.cend(); ++ip)
    {
        for(ip_type::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    try
    {
        
        ip_pool_type ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        // TODO reverse lexicographically sort
        std::sort(ip_pool.begin(),ip_pool.end(),[](const ip_type& a,const ip_type& b){
            if (a[0]==b[0]){
                if (a[1]==b[1]){
                    return std::stoi(a[2])>std::stoi(b[2]);
                }
                return std::stoi(a[1])>std::stoi(b[1]);
            }
            return std::stoi(a[0])>std::stoi(b[0]);
        });

        printIpPool(ip_pool);
        printf("++++++++++++\n");
        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        auto filterFirst = [&ip_pool](int fisrt){
            ip_pool_type ip{};
            for (const auto & v:ip_pool){
                if (v[0]==std::to_string(fisrt)){
                    ip.push_back(v);
                }
            }
            return ip;
        };
        auto ip = filterFirst(1);
        printIpPool(ip);
        printf("++++++++++++\n");
        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8
        ip.clear();
        // TODO filter by first and second bytes and output
        auto filter = [&ip_pool](int fisrt, int second){
            ip_pool_type ip{};
            for (const auto & v:ip_pool){
                if ((v[0]==std::to_string(fisrt))&&(v[1]==std::to_string(second))){
                    ip.push_back(v);
                }
            }
            return ip;
        };
        ip = filter(46, 70);
        printIpPool(ip);
        printf("++++++++++++\n");
        ip.clear();
        auto filterAny = [&ip_pool](int any){
            ip_pool_type ip{};
            for (const auto & v:ip_pool){
                if ((v[0]==std::to_string(any))||(v[1]==std::to_string(any))||(v[2]==std::to_string(any))||(v[3]==std::to_string(any))){
                    ip.push_back(v);
                }
            }
            return ip;
        };
        ip = filterAny(46);
        printIpPool(ip);
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
