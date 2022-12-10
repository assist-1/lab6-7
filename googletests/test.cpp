#include <gtest/gtest.h>
#include "/mnt/c/Users/79875/Desktop/c++/laba_PL#6-7/header.hpp"
//enter
TEST (RandomNum, Test1) {
    for (size_t i = 0; i<5;++i){
        EXPECT_NE(i, RandomNumber(5, 10));
    }
}

TEST (VuzConsruct, Test1) {
    MIEM_ID id;
    EXPECT_EQ(id.parametrs.size(), 5);
}

TEST (VuzConsruct, Test2) {
    MGTU_ID id;
    EXPECT_EQ(id.parametrs.size(), 5);
}

TEST (Generatr, Test1){
    MIEM_ID id;
    std::string ID = id.generate(1,2022,12,3);
    EXPECT_EQ( ID.size(), 15);
}

TEST (Generatr, Test2){
    MGTU_ID id;
    std::string ID = id.generate(1,2022,12,3);
    EXPECT_EQ( ID.size(), 14);
}

TEST(Pattern, Test1){
    Generator templateGenerator;
    EXPECT_EQ(templateGenerator.generator("MIEM")->generate(1,2022,12,3).size(),15);
}

TEST(Pattern, Test2){
    Generator templateGenerator;
    EXPECT_EQ(templateGenerator.generator("MGTU")->generate(1,2022,12,3).size(),14);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
