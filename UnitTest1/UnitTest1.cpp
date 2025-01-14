#include "CppUnitTest.h"
#include "..\app\money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;
using namespace vsite::oop::v7;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMoney)
		{
			money m(0);
			Assert::IsTrue(std::is_class_v<money>);
			Assert::IsFalse(std::is_abstract_v<money>);
			Assert::IsTrue(std::is_same_v<money, decltype(m)>);
		}

		TEST_METHOD(test_add)
		{
			money m(3, 35);
			money t(0, 60);
			m += t;
			Assert::AreEqual(395, m.total);
		}

		TEST_METHOD(test_subtract)
		{
			money m(4, 35);
			money t(0, 80);
			m -= t;
			Assert::AreEqual(355, m.total);
		}

		TEST_METHOD(test_overflow)
		{
			money total(0, 100);

			total += money(0, 70);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("1 e i 70 c."s, ss1.str());

			total += money(0, 280);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("4 e i 50 c."s, ss2.str());

			total += money(17, 38);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("21 e i 88 c."s, ss3.str());
		}

		TEST_METHOD(test_underflow)
		{
			money total(0, 1439);

			total -= money(5, 70);
			std::stringstream ss1;
			ss1 << total;
			Assert::AreEqual("8 e i 69 c."s, ss1.str());

			total -= money(0, 250);
			std::stringstream ss2;
			ss2 << total;
			Assert::AreEqual("6 e i 19 c."s, ss2.str());

			total -= money(0, 30);
			std::stringstream ss3;
			ss3 << total;
			Assert::AreEqual("5 e i 89 c."s, ss3.str());

			total -= money(5, 00);
			std::stringstream ss4;
			ss4 << total;
			Assert::AreEqual("89 c."s, ss4.str());
		}

		TEST_METHOD(TestZeroEur)
		{
			std::stringstream ss;
			money m(0, 50);
			ss << m;
			Assert::AreEqual("50 c."s, ss.str());
		}

		TEST_METHOD(TestZeroCent)
		{
			std::stringstream ss;
			money m(5);
			ss << m;
			Assert::AreEqual("5 e."s, ss.str());
		}

	};
}
