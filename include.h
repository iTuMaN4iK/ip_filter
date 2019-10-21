#include <vector>
#include <string>
#include <iostream>


using ip_pool_type =std::vector<std::vector<int>>;
using ip_type = std::vector<int>;


// ip_type split(const std::string &str, char d)
ip_type splitToInt(const std::string &str, char d)
{
    ip_type r;

    std::string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(std::stoi(str.substr(start)));

    return r;
}

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

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
ip_pool_type fiterFirstSecond(ip_pool_type & ip_pool,int f,int s){
    ip_pool_type result;
    for (const auto & v:ip_pool){
        if ((v[0]==f)&&(v[1]==s)){
            result.push_back(v);
        }
    }
    return result;
    
}
ip_pool_type filterAny(ip_pool_type & ip_pool,int any){
    ip_pool_type result;
    for (const auto & v:ip_pool){
        if ((v[0]==any)||(v[1]==any)||(v[2]==any)||(v[3]==any)){
            result.push_back(v);
        }
    }
    return result;
}

ip_pool_type filterFirst(ip_pool_type & ip_pool,int fisrt) {
    ip_pool_type ip{};
    for (const auto & v:ip_pool){
        if (v[0]==fisrt){
            ip.push_back(v);
        }
    }
    return ip;
}