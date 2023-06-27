#include <iostream>
#include <fstream>
#include <cctype>


class FileFilter {
public:
	virtual char transform(char ch) = 0; 
	void doFilter(std::fstream& in, std::fstream& out) {  //filter function to be used
		char ch;//to be used in all subclasses
		in.get(ch);//counts spaces and goes through file
		while (!in.eof()) {
			out << transform(ch);
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
		if (ch == '#') {
			flag = true;
			return ch;
		}
		else if (ch == '\n') {
			flag = false;
			return ch;
		}
		else if (flag) {
			return ch;
		}
		else {
		return ch - key;	//everything on file, adding key to the previous value
		}
	}
};
class Decrypt : public FileFilter {
	int key;
public:
	Decrypt(int key) {//takes key and puts it into private int
		this->key = key;
	}
	char transform(char ch) {//encryption works by changing ascii values of
		static bool flag2 = true;
		if (flag2 && ch!='\n') {
			return ch;
		}
		else if (ch == '\n') {
			flag2 = false;
			return ch;
		}
		else {
			return ch + key;	//everything on file, adding key to the previous value
		}
	}
};

void EncryptFile() {
	std::fstream in,out;
	Encrypt secure;
	in.open("ManagerSheet.txt", std::ios::in);
	out.open("SecureManagerSheet.txt", std::ios::out);
	if (!in) {
		std::cout << "\nCan't open in encrypt file";
		exit(1);
	}
	if (!out) {
		std::cout << "\nCan't open out encrypt file";
		exit(1);
	}
	secure.doFilter(in,out);
	in.close();
	out.close();
	remove("ManagerSheet.txt");
}
void DecryptFile(int key) {
	std::fstream in, out;
	Decrypt unlock(key);
	in.open("SecureManagerSheet.txt", std::ios::in);
	out.open("ManagerSheet.txt", std::ios::out);
	if (!in) {
		std::cout << "\nCan't open in decrypt file";
		exit(1);
	}
	if (!out) {
		std::cout << "\nCan't open out decrypt file";
		exit(1);
	}
	unlock.doFilter(in,out);
	in.close();
	out.close();
}