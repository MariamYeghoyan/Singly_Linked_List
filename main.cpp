#include "list.h"

int main() {
    SinglyList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    SinglyList<int> list2 = {4, 5, 6};

    SinglyList<int> list3(list1);

    SinglyList<int> list4(std::move(list2));

    list2 = list1;

    list3 = std::move(list4);

    std::cout << "Size of list1: " << list1.size() << std::endl;

    std::cout << "Value 2 is present in list1: " << list1.search(2) << std::endl;

    list1.insert(1, 10);

    list1.del(2);

    list1.reverse();

    for (auto it = list1.begin(); it != list1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    auto start = list1.begin();
    auto end = list1.end();
    list1.remove_if(start, end, [](int val) { return val % 2 == 0;});

    for (auto it = list1.begin(); it != list1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}