#include <iostream>
#include <fstream>
#include <cctype>


//abstract class
class FileFilter {
public:
	virtual char transform(char ch) = 0;   //abstract function

	void doFilter(std::fstream& file) { 
		std::fstream in;
		char ch;
		in.get(ch);//counts spaces and goes through file
		while (!in.eof()) {
			file << transform(ch);
			in.get(ch);

		}
	}

};

class Encrypt : public FileFilter {
	int key;
public:
	Encrypt() {//takes key and puts it into private int
		this->key = 11;
	}
	char transform(char ch) {//encryption works by changing ascii values of
		static bool flag = false;
		if (ch == '#' || flag) {
			return ch;
		}
		else {
		return ch + key;	//everything on file, adding key to the previous value
		}
	}
};

void EncryptFile() {
	std::fstream file;
	Encrypt secure;
	file.open("ManagerSheet.txt", std::ios::in |std::ios::out);
	if (!file) {
		std::cout << "\nCan't open file";
		exit(1);
	}
	secure.doFilter(file);
}