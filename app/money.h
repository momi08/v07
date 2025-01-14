#pragma once

#include <iostream>
#include <algorithm>
#include <format>

namespace vsite::oop::v7
{

	class money {
	
	public:

		int total;
		money(int e = 0, int c = 0);

		money& operator +=(const money& m);
		money& operator -=(const money& m);

		friend std::istream& operator >> (std::istream& is, money& m);
		friend std::ostream& operator << (std::ostream& os, const money& m);
	};
}