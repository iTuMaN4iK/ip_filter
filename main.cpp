#include "lib.h"
#include <cassert>
#include <cstdlib>
#include <algorithm>

#include "include.h"
#define UNUSED(variable) (void)variable
int main(int , char const *[])
{
    try
    {
        ip_pool_type ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            auto v2 = split(v.at(0), '.');
            ip_type tmp;
            tmp.reserve(v2.size());
            std::transform(v2.begin(),v2.end(),std::back_inserter(tmp),[](const std::string & str){return std::stoi(str);});
            ip_pool.push_back(tmp);
        }
        std::sort(ip_pool.begin(),ip_pool.end(),[](const ip_type& a,const ip_type& b){
            if (a[0]==b[0]){
                if (a[1]==b[1]){
                    if (a[2]==b[2]){
                        return a[3]>b[3];
                    }
                    return a[2]>b[2];                    
                }
                return a[1]>b[1];
            }
            return a[0]>b[0];
        });

        printIpPool(ip_pool);
        printIpPool(filterFirst(ip_pool,1));
        printIpPool(fiterFirstSecond(ip_pool,46, 70));
        printIpPool(filterAny(ip_pool,46)); 
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
