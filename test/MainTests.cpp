

#include <C:\Users\User\Documents\VS Projects\STLExercises\Headers\DesignPatterns.hpp> 
#include <gtest/gtest.h>



TEST(STLExercises, TestMacrosCollection)
{
    ASSERT_TRUE(true);
    EXPECT_TRUE(true);
    EXPECT_EQ(1, true) << "***** TEST FAILED COMPARISON  *****";
}


TEST (STLExercises, MAC){
    int x=42;
    int y=12;
    int sum=58;
    //EXPECT_EQ(MAC(x,y,sum), sum) << "Function dont work";
}
