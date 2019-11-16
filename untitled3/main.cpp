#include <functional>
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *address = &a;
    auto refForAddress = std::ref(const_cast<int *const>(address));
    cout << "a的地址为" << address << "address指向的值" << *address << endl;
    cout << "a的ref为" << refForAddress << "ref指向的值为" << *refForAddress << endl;

    address += 10;
    *refForAddress = 123123;
    // refForAddress = refForAddress + 10;
    cout << "改变后的值" << address << endl;
    cout << "ref的值为" << refForAddress << endl;
    return 0;
}
