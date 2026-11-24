#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_1_A/Lab_10_1_A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
    TEST_CLASS(UnitTest101A)
    {
    public:
        TEST_METHOD(TestCountExcellentA)
        {
            const int N = 3;
            Student s[N];

            s[0] = { "Sydorenko", 1, KN, 5, 5, 5 };
            s[1] = { "Petrenko", 2, INF, 5, 4, 5 };
            s[2] = { "Kovalchuk", 1, ME, 3, 5, 4 };

            int cFiz = 0, cMat = 0, cInf = 0;
            CountExcellentPerSubject(s, N, cFiz, cMat, cInf);

            Assert::AreEqual(2, cFiz);
            Assert::AreEqual(2, cMat);
            Assert::AreEqual(2, cInf);
            Assert::AreEqual(1, CountExcellentFizAndMat(s, N));
        }
    };
}