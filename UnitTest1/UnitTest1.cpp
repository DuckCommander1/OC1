#include <string>
#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"

#include "../Multithread1/Multithread1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		 
		TEST_METHOD(TestMethod1)
		{
			int expectedMin = 5;
			int testArray[] = { 5, 10, 54, 9999, 7 };

			std::stringstream input("5 5 10 54 9999 7");
			std::stringstream output;

			cin.rdbuf(input.rdbuf());
			cout.rdbuf(output.rdbuf());
			int a = main();
			
			int res = stoi(output.str().substr(33));

			Assert::AreEqual(expectedMin, res);
		}

		TEST_METHOD(TestMethod2) {
			int expectedMin = -98;
			string testArray = "7 1234 -79 54 9999 -81 341 -98";

			std::stringstream input(testArray);
			std::stringstream output;

			cin.rdbuf(input.rdbuf());
			cout.rdbuf(output.rdbuf());
			int a = main();

			int res = stoi(output.str().substr(33));

			Assert::AreEqual(expectedMin, res);
		}

		TEST_METHOD(TestMethodError) {
			string expected = "Invalid size";
			string testArray = "-7 1 -17 45";

			std::stringstream input(testArray);
			std::stringstream output;

			cin.rdbuf(input.rdbuf());
			cout.rdbuf(output.rdbuf());
			int a = main();

			Assert::AreEqual(expected, output.str().substr(16));
		}
	};
}
