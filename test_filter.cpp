#include <gtest/gtest.h>
#include "include.h"
TEST(TestFilters,fiterFirstSecond){
    ip_pool_type source={{1,2,3,4},
                         {5,6,7,8},
                         {2,1,7,8},
                         {1,1,2,8},
                         {2,1,2,8},                   
                         {2,1,1,2},      
                        };
    ip_pool_type result={{1,2,3,4}               
    };
    ip_pool_type test=fiterFirstSecond(source,1,2);
    ASSERT_EQ(test.size(),result.size());
    for (std::size_t i{};i<result.size();i++){
        ASSERT_EQ(test[i],result[i]);
    }
}
TEST(TestFilters,filterAny){
    ip_pool_type source={{5,189,203,46},
                         {5,6,46,8},
                         {2,46,7,8},
                         {46,1,2,8},
                         {2,1,2,8},                   
                         {46,46,46,46},      
                        };
    ip_pool_type result={{5,189,203,46},
                         {5,6,46,8},
                         {2,46,7,8},
                         {46,1,2,8},                
                         {46,46,46,46},      
                        };
    ip_pool_type test=filterAny(source,46);
    ASSERT_EQ(test.size(),result.size());
    for (std::size_t i{};i<result.size();i++){
        ASSERT_EQ(test[i],result[i]);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}