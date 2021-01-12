#include "pch.h"
#include "CppUnitTest.h"
#include "../9.1 в/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			Student* s = new Student[N];
			s[0].prizv = "Калимон";
			s[0].kurs = 1;
			s[0].specialty = TN;
			s[0].physics = 5;
			s[0].math = 5;
			s[0].pedagogika = 5;
			s[1].prizv = "Іваненко";
			s[1].kurs = 2;
			s[1].specialty = KN;
			s[1].physics = 3;
			s[1].math = 4;
			s[1].informatics = 5;
			Assert::AreEqual(well_students(s, 2), 50.);
			delete[] s;
		}
	};
}
