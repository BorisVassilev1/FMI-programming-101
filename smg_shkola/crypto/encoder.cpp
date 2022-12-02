#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int file_count = 3;

	for (int i = 1; i <= file_count; ++i) {
		string	 in_name  = "./smg_shkola/crypto/message_" + to_string(i) + ".txt";
		string	 out_name = "./smg_shkola/crypto/message_" + to_string(i) + "_enc.txt";
		string	 key_name = "./smg_shkola/crypto/message_" + to_string(i) + "_key.txt";
		ifstream in(in_name, ios::binary);
		if (!in.good()) {
			cerr << "bad file!!: " << in_name << endl;
			continue;
		}
		ifstream fkey(key_name);
		if (!fkey.good()) {
			cerr << "bad file!!: " << key_name << endl;
			continue;
		}
		char key[100];
		fkey.getline(key, 100);
		int keylen = strlen(key);
		cout << "key length: " << keylen << endl;

		ofstream out(out_name, ios::binary);

		unsigned int counter = 0;
		while (!in.eof()) {
			unsigned char curr = in.get();
			if (in.fail()) break;

			curr ^= key[counter % keylen];

			out << curr;
			++counter;
		}
		cout << "message length: " << counter << endl;

		in.close();
		out.close();
	}
	return 0;
}