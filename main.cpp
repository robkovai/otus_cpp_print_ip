#include "print_ip.h"

/**
 * @mainpage
 * Утилита для печати в консоль ip-адресов
 *
 * print_ip может работать с разными типами:
 * - любой целочисленный тип
 * - std::string
 * - любой контейнер
 * - std::tuple
 */

using namespace std;

int main() {
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(2130706433);
    print_ip(8875824491850138409);
    print_ip(string("192.168.1.1"));
    print_ip(vector<unsigned char>{ 192, 168, 1, 2 });
    print_ip(list<unsigned char>{ 192, 168, 1, 3 });
    print_ip(make_tuple(192, 168, 1, 4));
    return 0;
}
