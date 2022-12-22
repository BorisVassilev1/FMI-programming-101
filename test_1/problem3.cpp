#include <iostream>
#include <limits>

int main() {
	// брой точки
	int n;
	std::cin >> n;
	// просто ще намерим точна горна и долна граница на множествата
	// от x и y
	if (n == 0) return 0;

	// подходящи начални стойности за min и max
	double min_x = std::numeric_limits<double>::max(),
	min_y = std::numeric_limits<double>::max(), 
	max_x = std::numeric_limits<double>::lowest(),
	max_y = std::numeric_limits<double>::lowest();

	for(int i = 0; i < n; ++ i) {
		// координати на текущата точка
		double x, y;
		std::cin >> x >> y;
		
		if(x > max_x) max_x = x;
		if(x < min_x) min_x = x;

		if(y > max_y) max_y = y;
		if(y < min_y) min_y = y;
	}
	
	// тъй като търсим квадрат, взимаме по-голямата от двете разлики
	double side = std::max((max_y - min_y) , (max_x - min_x));
	// и смятаме лицето
	double area = side * side;
	
	std::cout << area << std::endl;
}