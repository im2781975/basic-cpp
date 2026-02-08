#include <iostream>
#include <vector>
#include <algorithm>

struct Element {
    int value;
    int originalIndex;
};

bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Element> elements(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i].value;
        elements[i].originalIndex = i;
    }

    std::sort(elements.begin(), elements.end(), compareElements);

    std::cout << "Value " << elements[0].value << ", Previous Index " << elements[0].originalIndex << std::endl;
    for (int i = 1; i < n; ++i) {
        if (elements[i].value == elements[i - 1].value) {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i - 1].originalIndex << std::endl;
        } else {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i].originalIndex << std::endl;
        }
    }

    return 0;
}

