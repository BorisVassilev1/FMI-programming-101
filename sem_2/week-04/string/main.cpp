#include <iostream>
#include "vector.hpp"
#include "string.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("VECTORS test") {
	SUBCASE("vector creation") {
		vector<int> v;
		v.push(1);
		v.push(2);
		v.push(3);
		CHECK(v[0] == 1);
		CHECK(v[1] == 2);
		CHECK(v[2] == 3);
	}
	SUBCASE("vector sum") {
		vector<int> a, b;
		vector<int> c;
		a.push(1);
		a.push(2);
		b.push(3);
		b.push(4);
		c.push(1);
		c.push(2);
		c.push(3);
		c.push(4);
		CHECK(a + b == c);
	}
	SUBCASE("vector substring") {
		vector<int> a;
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		vector<int> b;
		b.push(2);
		b.push(3);
		CHECK(a.substr(1, 2) == b);
	}
}

TEST_CASE("STRINGS test") {
	string a("Hello"), b("World"), c("Hello World");
	SUBCASE("string indexing") {
		CHECK(a[0] == 'H');
		CHECK(a[1] == 'e');
		CHECK(a[2] == 'l');
		CHECK(a[3] == 'l');
		CHECK(a[4] == 'o');
		CHECK(a[5] == '\0');
	}
	SUBCASE("string push") {
		a.push('a');
		a.push('s');
		a.push('d');
		CHECK(a == string("Helloasd"));
	}
	SUBCASE("string pop") {
		a.pop();
		a.pop();
		a.pop();
		CHECK(a == string("He"));
	}
	SUBCASE("string equality") {
		string d("Hello");
		CHECK(a == d);
	}
	SUBCASE("string sum") {
		CHECK(a + " " + b == c);
	}
	SUBCASE("string +=") {
		a += " ";
		a += b;
		CHECK(a == c);
	}
	SUBCASE("substrings") {
		CHECK((a + b).substr(2, 5) == string("lloWorld"));
	}
	SUBCASE("strings comparison") {
		CHECK(a < b);
		CHECK_FALSE(a >= b);
	}
	SUBCASE("empty strings") {
		a.clear();
		CHECK(a == string(""));
	}
}
