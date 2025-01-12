#pragma once

#include <iostream>
#include <algorithm>
#include <format>

namespace vsite::oop::v7
{

	class money {
		int total;

	public:

		money(int e = 0, int c = 0);

		money& operator +=(const money& m);
		money& operator -=(const money& m);

		friend std::istream& operator >> (std::istream& is, money& m);
		friend std::ostream& operator << (std::ostream& os, const money& m);


		int get_value() const;
		void add_value(int addt, int dec);
		void sub_value(int subs, int dec);
	};


}