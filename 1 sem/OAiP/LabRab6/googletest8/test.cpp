#include "pch.h"
#include <iostream>  
#include <string> 

std::string task8()
{
    std::string s1;
    std::string s2;
    long long kol;
    std::cin >> kol;
    while (kol)
    {
        std::cin >> s1;
        std::cin >> s2;
        long long  index = 0, index2 = 1;
        long long ist = 0, jst = 0;
        long long konec1 = 0, konec2 = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[0])
            {
                index = i;
                ist++;
                jst++;
                konec1 = 1;
            }
            if (konec1 == 1) break;
        }

        if (index == s1.size() - 1 && s1.size() == s2.size())
        {
            index = index - 2;
        }

        ++index;

        for (index; index < s1.size(); index++)
        {
            if (s1[index] == s2[jst])
            {
                ist++;
                jst++;
            }
            if (ist == s2.size()) konec2 = 1;
            if (konec2 == 1) break;
            index2 = index;
        }

        index2--;

        for (index2; index2 > -1; index2--)
        {

            if (s1[index2] == s2[jst])
            {
                ++ist;
                jst++;

            }
        }

        if (ist == s2.size())
        {
            std::cout << "YES" << "\n";
            return "YES";
            kol--;
            continue;
        }
        return "NO";
        kol--;
    }
}

TEST(Test1) {
    //1  567   765
    EXPECT_EQ(task8(), "YES");
}
TEST(Test2) {
    // 1   vitaliy vitalik
    EXPECT_EQ(task8(), "NO");
}
TEST(Test3) {
    // 1   ñupcake cakecup
    EXPECT_EQ(task8(), "NO");
}