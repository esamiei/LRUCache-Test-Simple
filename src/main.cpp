#include "LRUCache.hpp"
#include "gtest/gtest.h"


TEST(CacheTest, SimplePut) {
    lrucachedef::LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    EXPECT_EQ(1,obj.get(1));
    obj.put(3,3);
    EXPECT_EQ(-1,obj.get(2));

}

int main(int argc,char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}