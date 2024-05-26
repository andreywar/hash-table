#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class HashTable {
private:
    unordered_map<int, int> table;

public:
    void insert(int key, int value) {
        table[key] = value;
    }

    int search(int key) {
        if (table.find(key) != table.end()) {
            return table[key];
        }
        else {
            return -1;
        }
    }
    void remove(int key) {
        if (table.find(key) != table.end()) {
            cout << "Removing key: " << key << ", Value: " << table[key] << endl;
            table.erase(key);
        }
        else {
            cout << "Key " << key << " not found for deletion." << endl;
        }
    }
    void removeRandom() {
        if (table.empty()) {
            cout << "Table is empty. Cannot remove." << endl;
            return;
        }

        auto it = next(begin(table), rand() % table.size());
        int key = it->first;
        int value = it->second;

        cout << "Removing key: " << key << ", Value: " << value << endl;

        table.erase(key);
    }

    void printTable() {
        for (const auto& pair : table) {
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
    }
};

int main() {
    srand(time(NULL));

    HashTable ht;

    for (int i = 0; i < 10; ++i) {
        int key = rand() % 100;
        int value = rand() % 1000;
        ht.insert(key, value);
    }

    cout << "Table Contents:" << endl;
    ht.printTable();

    int keyToFind = 5;
    int result = ht.search(keyToFind);
    if (result != -1) {
        cout << "Found value for the key " << keyToFind << ": " << result << endl;
    }
    else {
        cout << "Key value " << keyToFind << " not found." << endl;
    }

    for (int i = 0; i < 3; ++i) {
        ht.removeRandom();
    }

    cout << "Table contents after deletion:" << endl;
    ht.printTable();

    return 0;
}
