#include <iostream>
#include <stdio.h>
#include "Encryption.h"

int main() {
	std::fstream file;
	file.open("ManagerSheet.txt", std::ios::in|std::ios::out);
	if (!file) {
		std::cout << "\nCan't open file";
		exit(1);
	}
	Encrypt.doFilter(file,file)

}
