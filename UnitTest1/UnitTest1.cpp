#include "pch.h"
#include "CppUnitTest.h"
#include "../81 rek/Source.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            char str1[] = "abc aabbccabc";
            char str2[] = "abc abcg abcgg";
            char str3[] = "xyz";

            Assert::AreEqual(4, countLetterGroupsRecursive(str1));
            Assert::AreEqual(3, countLetterGroupsRecursive(str2));
            Assert::AreEqual(0, countLetterGroupsRecursive(str3));

            char* modifiedStr1 = ChangeRecursive(str1, 14);
            char* modifiedStr2 = ChangeRecursive(str2, 15);
            char* modifiedStr3 = ChangeRecursive(str3, 4);

            Assert::AreEqual("** ******", modifiedStr1);
            Assert::AreEqual("** **g **gg", modifiedStr2);
            Assert::AreEqual("xyz", modifiedStr3);
            delete[] modifiedStr1;
            delete[] modifiedStr2;
            delete[] modifiedStr3;
        }
    };
}