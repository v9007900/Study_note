#include <iostream>
#include <limits>
using namespace std;
int main()
{
     cout << "bool:\t\t\t" << sizeof(bool) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<bool>::min() << "~" << numeric_limits<bool>::max() << endl;
     cout << "char:\t\t\t" << sizeof(char) << "\t×Ö½Ú\t"
          << "·¶Î§:" << (int)numeric_limits<char>::min() << "~" << (int)numeric_limits<char>::max() << endl;
     cout << "signed char:\t\t" << sizeof(signed char) << "\t×Ö½Ú\t"
          << "·¶Î§:" << (int)numeric_limits<signed char>::min() << "~" << (int)numeric_limits<signed char>::max() << endl;
     cout << "unsigned char:\t\t" << sizeof(unsigned char) << "\t×Ö½Ú\t"
          << "·¶Î§:" << (int)numeric_limits<unsigned char>::min() << "~" << (int)numeric_limits<unsigned char>::max() << endl;
     cout << "int:\t\t\t" << sizeof(int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<int>::min() << "~" << numeric_limits<int>::max() << endl;
     cout << "signed int:\t\t" << sizeof(signed int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<signed int>::min() << "~" << numeric_limits<signed int>::max() << endl;
     cout << "signed:\t\t\t" << sizeof(signed) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<signed>::min() << "~" << numeric_limits<signed>::max() << endl;
     cout << "unsigned int:\t\t" << sizeof(unsigned int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned int>::min() << "~" << numeric_limits<unsigned int>::max() << endl;
     cout << "unsigned:\t\t" << sizeof(unsigned) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned>::min() << "~" << numeric_limits<unsigned>::max() << endl;
     cout << "short int:\t\t" << sizeof(short int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<short int>::min() << "~" << numeric_limits<short int>::max() << endl;
     cout << "short:\t\t\t" << sizeof(short) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<short>::min() << "~" << numeric_limits<short>::max() << endl;
     cout << "signed short int:\t" << sizeof(signed short int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<signed short int>::min() << "~" << numeric_limits<signed short int>::max() << endl;
     cout << "unsigned short int:\t" << sizeof(unsigned short int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned short int>::min() << "~" << numeric_limits<unsigned short int>::max() << endl;
     cout << "long int:\t\t" << sizeof(long int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<long int>::min() << "~" << numeric_limits<long int>::max() << endl;
     cout << "long:\t\t\t" << sizeof(long) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<long>::min() << "~" << numeric_limits<long>::max() << endl;
     cout << "signed long int:\t" << sizeof(signed long int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<signed long int>::min() << "~" << numeric_limits<unsigned long int>::max() << endl;
     cout << "unsigned long int:\t" << sizeof(unsigned long int) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned long int>::min() << "~" << numeric_limits<unsigned long int>::max() << endl;
     cout << "float:\t\t\t" << sizeof(float) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<float>::min() << "~" << numeric_limits<float>::max() << endl;
     cout << "double:\t\t\t" << sizeof(double) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<double>::min() << "~" << numeric_limits<double>::max() << endl;
     cout << "long double:\t\t" << sizeof(long double) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<long double>::min() << "~" << numeric_limits<long double>::max() << endl;
     cout << "wchar_t:\t\t" << sizeof(wchar_t) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<wchar_t>::min() << "~" << numeric_limits<wchar_t>::max() << endl;
     cout << "unsigned:\t\t" << sizeof(unsigned) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned>::min() << "~" << numeric_limits<unsigned>::max() << endl;
     cout << "long long:\t\t" << sizeof(long long) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<long long>::min() << "~" << numeric_limits<long long>::max() << endl;
     cout << "unsigned long long:\t" << sizeof(unsigned long long) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<unsigned long long>::min() << "~" << numeric_limits<unsigned long long>::max() << endl;
     cout << "char16_t:\t\t" << sizeof(char16_t) << "\t×Ö½Ú\t"
          << "·¶Î§:" << numeric_limits<char16_t>::min() << "~" << numeric_limits<char16_t>::max() << endl;

     return 0;
}
