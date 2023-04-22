#include <iostream>
#include <cstring>
#include <cstddef>
#include <fstream>
#include <vector>

const int PENCIL_BRAND_LENGTH = 100;

class Pencil {
	char		 brand[PENCIL_BRAND_LENGTH + 1];
	unsigned int year;
	unsigned int hardness;

	void setBrand(const char *brand) { strcpy(this->brand, brand); }

   public:
	Pencil() : year(0), hardness(0) { setBrand("Dummy"); }
	Pencil(const char *brand, unsigned int year, unsigned int hardness) : year(year), hardness(hardness) {
		setBrand(brand);
	}

	const char	*getBrand() const { return brand; }
	unsigned int getYear() const { return year; }
	unsigned int getHardness() const { return hardness; }

	friend std::istream &operator>>(std::istream &in, Pencil &p);
};

std::ostream &operator<<(std::ostream &out, const Pencil &p) {
	return out << "Pencil: { " << p.getYear() << ", " << p.getHardness() << ", " << p.getBrand() << "}";
}

std::istream &operator>>(std::istream &in, Pencil &p) {
	return in >> p.year >> p.hardness >> p.brand;
}

void readPencils(const char *fileName, std::vector<Pencil> &vec) {
	std::ifstream in(fileName);
	if (!in) return;

	while (!in.eof()) {
		Pencil p;
		in >> p;
		if (in) vec.push_back(p);
	}

	in.close();
}

void writePencils(const char *fileName, const std::vector<Pencil> &pencils, const char *brand) {
	std::ofstream out(fileName);
	for (const Pencil &p : pencils) {
		if (strcmp(p.getBrand(), brand) == 0) { out << p << '\n'; }
	}
	out.flush();
	out.close();
}

int main() {
	std::vector<Pencil> pencils;

	readPencils("pencils.txt", pencils);

	char brand[100];
	std::cin >> brand;

	writePencils("brand.txt", pencils, brand);
	return 0;
}
