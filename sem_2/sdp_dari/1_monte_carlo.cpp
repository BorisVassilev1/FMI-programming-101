#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

double findPI(unsigned n) {
	// init random device
	std::random_device				 rd;
	std::default_random_engine		 e2(rd());
	std::uniform_real_distribution<> rand(0, 1);

	// count samples
	double	 x, y;
	double dist;
	unsigned inCircleCount = 0;
	for (unsigned i = 0; i < n; ++i) {
		x			= rand(e2);
		y			= rand(e2);
		dist = x * x + y * y;
		if (dist < 1.) ++inCircleCount;
	}

	// and calculate PI
	double pi = 4. * ((double)inCircleCount / n);
	return pi;
}

int main() {
	const unsigned pointsCount[]{4000, 8000, 16000, 32000};
	const double   PI = std::atan(1.0) * 4;

	// test with different point counts	
	for (unsigned i = 0; i < 4; ++i) {

		double pi	= findPI(pointsCount[i]);
		double diff = PI - pi;
		
		std::cout << "Points Count: " << pointsCount[i] << '\n';
		std::cout << "Calculated PI: " << pi << '\n';
		std::cout << "Error: " << diff << '\n' << std::endl;
	}

	return 0;
}