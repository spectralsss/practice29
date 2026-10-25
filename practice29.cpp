#include <iostream>

struct WordCount {
    char word[100];
    int count;
};

int main() {
    WordCount items[1000];
    int size = 0;
    char buffer[100];

    while (std::cin >> buffer) {
        for (int i = 0; buffer[i] != '\0'; ++i) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] += 32;
            }
        }

        int found_index = -1;
        for (int i = 0; i < size; ++i) {
            bool equal = true;
            int j = 0;
            while (items[i].word[j] != '\0' || buffer[j] != '\0') {
                if (items[i].word[j] != buffer[j]) {
                    equal = false;
                    break;
                }
                j++;
            }
            if (equal) {
                found_index = i;
                break;
            }
        }

        if (found_index != -1) {
            items[found_index].count++;
        }
        else if (size < 1000) {
            int j = 0;
            while (buffer[j] != '\0') {
                items[size].word[j] = buffer[j];
                j++;
            }
            items[size].word[j] = '\0';
            items[size].count = 1;
            size++;
        }
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            bool swap_needed = false;
            int k = 0;
            while (items[j].word[k] != '\0' && items[j + 1].word[k] != '\0') {
                if (items[j].word[k] > items[j + 1].word[k]) {
                    swap_needed = true;
                    break;
                }
                else if (items[j].word[k] < items[j + 1].word[k]) {
                    break;
                }
                k++;
            }
            if (!swap_needed && items[j].word[k] != '\0' && items[j + 1].word[k] == '\0') {
                swap_needed = true;
            }

            if (swap_needed) {
                WordCount temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < size; ++i) {
        std::cout << items[i].word << " -> " << items[i].count << "\n";
        if (items[i].count > max_count) {
            max_count = items[i].count;
            max_index = i;
        }
    }

    if (size > 0) {
        std::cout << "\nНайчастіше слово: " << items[max_index].word << " -> " << max_count << "\n";
    }
}