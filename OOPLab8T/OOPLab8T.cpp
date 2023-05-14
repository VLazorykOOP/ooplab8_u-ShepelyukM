#include <iostream>
#include <cstring>

template<typename T>
T find_min(T* arr, int size) {
    T min_element = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
    }
    return min_element;
}

template<typename T>
T find_max(T* arr, int size) {
    T max_element = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    return max_element;
}

template<>
char* find_min<char*>(char** arr, int size) {
    char* min_element = const_cast<char*>(arr[0]);
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], min_element) < 0) {
            min_element = const_cast<char*>(arr[i]);
        }
    }
    return min_element;
}

template<>
char* find_max<char*>(char** arr, int size) {
    char* max_element = const_cast<char*>(arr[0]);
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], max_element) > 0) {
            max_element = const_cast<char*>(arr[i]);
        }
    }
    return max_element;
}

int main() {
    int int_arr[] = { 5, 2, 8, 1, 9, 4 };
    double double_arr[] = { 3.14, 2.71, 1.414, 1.732 };
    char* char_arr[] = { const_cast<char*>("apple"), const_cast<char*>("banana"), const_cast<char*>("orange"), const_cast<char*>("pear") };

    int int_min = find_min(int_arr, 6);
    int int_max = find_max(int_arr, 6);
    double double_min = find_min(double_arr, 4);
    double double_max = find_max(double_arr, 4);
    char* char_min = find_min(char_arr, 4);
    char* char_max = find_max(char_arr, 4);

    std::cout << "Min and Max of int_arr: " << int_min << ", " << int_max << std::endl;
    std::cout << "Min and Max of double_arr: " << double_min << ", " << double_max << std::endl;
    std::cout << "Min and Max of char_arr: " << char_min << ", " << char_max << std::endl;

    return 0;
}
_________________________________________________________________________________________________________

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> L = { 1, 2, 2, 3, 3, 1, 2, 2, 2, 4 };

    // Проходимось по списку з кінця та знаходимо ітератор на першу пару сусідніх елементів з однаковими значеннями
    auto adjacent_it = std::adjacent_find(L.rbegin(), L.rend());

    // Якщо така пара була знайдена, то подвоюємо значення в останній парі сусідніх елементів з однаковими значеннями
    if (adjacent_it != L.rend()) {
        // Знаходимо ітератор на початок останньої пари сусідніх елементів з однаковими значеннями
        auto last_pair_it = adjacent_it.base();

        // Подвоюємо значення в останній парі сусідніх елементів з однаковими значеннями
        *(last_pair_it - 1) *= 2;
        *(last_pair_it - 2) *= 2;
    }

    // Виводимо вміст списку L після виконання операції
    for (auto it = L.begin(); it != L.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
