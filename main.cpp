#include "lib.h"
#include <cassert>
#include <cstdlib>
#include <algorithm>

#include "include.h"
#define UNUSED(variable) (void)variable
int main(int argc, char const *argv[])
{
    try
    {
        UNUSED(argc);
        UNUSED(argv);

        ip_pool_type ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }
        std::sort(ip_pool.begin(),ip_pool.end(),[](const ip_type& a,const ip_type& b){
            if (a[0]==b[0]){
                if (a[1]==b[1]){
                    if (a[2]==b[2]){
                        return std::stoi(a[3])>std::stoi(b[3]);
                    }
                    return std::stoi(a[2])>std::stoi(b[2]);                    
                }
                return std::stoi(a[1])>std::stoi(b[1]);
            }
            return std::stoi(a[0])>std::stoi(b[0]);
        });

        printIpPool(ip_pool);
        auto filterFirst = [&ip_pool](int fisrt){
            ip_pool_type ip{};
            for (const auto & v:ip_pool){
                if (v[0]==std::to_string(fisrt)){
                    ip.push_back(v);
                }
            }
            return ip;
        };
        printIpPool(filterFirst(1));
        printIpPool(fiterFirstSecond(ip_pool,46, 70));
        printIpPool(filterAny(ip_pool,46)); 
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
