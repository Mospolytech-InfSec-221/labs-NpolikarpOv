#include <iostream>
#include <bitset>
using std::cin;

using std::cout;

using std::endl;

int main() {
	cout << "1.\n";
	cout << "Polikarpov Nikita 221 352\n";
	cout << "2.\n";
	cout << "min int = " << INT_MIN << "," << " max int = " << INT_MAX << ", " << " size = " << sizeof(int) << endl;
	cout << "min unsigned int = 0" << " ," << "max unsigned int = " << UINT_MAX << ", " << "size = " << sizeof(unsigned int) << endl;
	cout << "min short = " << SHRT_MIN << " ," << "max short = " << SHRT_MAX << " ," << "size = " << sizeof(short) << endl;
	cout << "min unsigned short = 0, max unsigned short = " << USHRT_MAX << ", " << "size = " << sizeof(unsigned short) << endl;
	cout << "min long = " << LONG_MIN << "max long = " << LONG_MAX << ", " << "size = " << sizeof(long) << endl;
	cout << "min unsigned long = 0, max unsigned long = " << ULONG_MAX << ", " << "size = " << sizeof(unsigned long) << endl;
	cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ", " << "size = " << sizeof(double) << endl;
	cout << "min char = " << CHAR_MIN << ", " << "max char = " << CHAR_MAX << ", " << "size = " << sizeof(char) << endl;
	cout << "min bool = " << false << ", " << "max bool = " << true << ", " << "size = " << sizeof(bool) << endl;
	cout << "3.\n";
	cout << "vvedite chislo : ";
	int number;
	cin >> number;
	cout << "bin = 0b" << std::bitset< 8 * sizeof(int)>(number) << endl;
	cout << "hex = 0x" << std::hex << number << endl;
	cout << "bool = " << bool(number) << endl;
	cout << "double = " << double(number) << endl;
	cout << "char = " << char(number) << endl;
	cout << std::dec;
	cout << "4.\n";
	cout << "vvedite koefficienti a * x = b: ";
	int q, w;
	cin >> q >> w;
	cout << q << " * x = " << w << endl;
	cout << "x = " << w << " / " << q << endl;
	cout << "x = " << w / q << endl;
	cout << "5.\n";
	cout << "vvedite koordinati otrezka : ";
	int z, v;
	cin >> z >> v;
	cout << "seredina otrezka nyahoditsya v tochke s koordinatami: " << (double(z) + v) / 2 << endl;
	return 0;
}
