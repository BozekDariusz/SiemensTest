#include "pch.h"
#include "CppUnitTest.h"
#include "../SiemensInterviewExercise/Airport.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestStripConstructor)
		{
			Strip strip(60);
			Assert::AreEqual(60, strip.timeToReady);

		}
		
		TEST_METHOD(TestAirportConstructor)
		{
			Airport airport;
			Assert::AreEqual(std::string("Big"), airport.Strips.find("Big")->first);
			Assert::AreEqual(std::string("Light"), airport.Strips.find("Light")->first);

		}
		TEST_METHOD(TestAirportAddNewStrip)
		{
			Airport airport;
			airport.addStrip("Large",17);
			Assert::AreEqual(std::string("Large"), airport.Strips.find("Large")->first);
			Assert::AreEqual(17, airport.Strips.find("Large")->second[0]->timeToReady);

		}
		TEST_METHOD(TestAirportAddExistingStrip)
		{
			Airport airport;
			airport.addStrip("Large", 17);
			airport.addStrip("Large", 23);
			Assert::AreEqual(std::string("Large"), airport.Strips.find("Large")->first);
			Assert::AreEqual(23, airport.Strips.find("Large")->second[1]->timeToReady);

		}

		TEST_METHOD(TestSizeOfStripWhenAdding)
		{
			Airport airport;
			airport.addStrip("Large", 17);
			airport.addStrip("Large", 23);
			Assert::AreEqual(size_t(2), airport.Strips.find("Large")->second.size());

		}
		TEST_METHOD(TestSizeOfStrip)
		{
			Airport airport;
			Assert::AreEqual(size_t(1), airport.Strips.find("Big")->second.size());

		}
		TEST_METHOD(TestAirportDeleteStrip)
		{
			Airport airport;
			airport.addStrip("Large", 17);
			airport.addStrip("Large", 23);
			airport.deleteStrip("Large");
			Assert::AreEqual(size_t(1), airport.Strips.find("Large")->second.size());
			Assert::AreEqual(17, airport.Strips.find("Large")->second[0]->timeToReady);

		}
	
	};
}
