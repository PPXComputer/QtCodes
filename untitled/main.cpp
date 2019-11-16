#include <iostream>
#include <random>
#include <vector>

using std::vector;
using index_t = unsigned long long; //长度单位
void quickSort(vector<int> &array);

void quickSort(vector<int> &array, index_t head, index_t tail);

index_t partition(vector<int> &array, index_t left, index_t right);

index_t usua_partition(vector<int> &array, index_t left, index_t right);

void quickSort(vector<int> &array)
{
    if (array.size() <= 1)
        return;

    quickSort(array, 0, array.size() - 1);
}
void quickSort(vector<int> &array, index_t head, index_t tail)
{
    if (head < tail) {
        auto index = usua_partition(array, head, tail);
        quickSort(array, index + 1, tail);
        quickSort(array, head, index - 1);
    }
}
index_t partition(vector<int> &array, index_t left, index_t right)
{
    int base = array[left]; // 取 第一个数为基准
    bool forward = true;
    while (left < right) {
        if (forward) {
            if (array[right] <= base) {
                array[left] = array[right];
                forward = true;
            }
            right--;
        } else {
            if (array[left] > base) {
                array[right] = array[left];
                forward = false;
            }
            left++;
        }
    }
    array[left] = base;
    return left;
}
index_t usua_partition(vector<int> &array, index_t left, index_t right)
{
    //这里是平常的 快速排序的写法
    auto base = array[left]; //取第一个数为基准数
    while (left < right) {
        while (left < right && array[right] >= base) {
            right--;
        }
        if (left < right) {
            array[left] = array[right];
            left++;
        }
        while (left < right && array[left] < base) {
            left++;
        }
        if (left < right) {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = base;
    return left;
}
int main()
{
    vector<int> array;
    array.resize(10);
    std::uniform_int_distribution<int> u(0, 100);
    std::default_random_engine e;
    for (int i = 0; i < 10; ++i) {
        array.emplace_back(u(e));
    }
    for (auto &sd : array) {
        std::cout << sd << " ";
    }
    std::cout << "         " << std::endl;
    quickSort(array);
    for (auto &sd : array) {
        std::cout << sd;
    }
    std::cout << "Hello World!" << std::endl;
    return 0;
}
