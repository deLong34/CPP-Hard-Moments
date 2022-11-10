#pragma once
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<istream>
#include<math.h>
#define _USE_MATH_DEFINES

void generateAnalogSignal(std::vector<double_t>& vec)
{
	generate(vec.begin(), vec.end(), [n = 0]() mutable
	{
		return sin(n++ * (2 * M_PI / 100)) * 10;
	});
}

double_t calculateSignalConversionError(std::vector<double_t>& aVec, std::vector<int64_t>& dVec)
{
	return inner_product(aVec.begin(), aVec.end(), dVec.begin(), 0.0,
		std::plus<double_t>{}, [](double_t a, int64_t b)
		{
			return std::pow(a - b, 2);
		});
}