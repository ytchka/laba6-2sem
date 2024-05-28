#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class InvalidArithmeticProgression : public invalid_argument {
public:
    InvalidArithmeticProgression(const string& what_arg) : invalid_argument(what_arg) {}
};

class ArithmeticProgression {
private:
    int firstElement;
    int difference;
    vector<int> progression;

public:
    ArithmeticProgression(int first, int diff, const vector<int>& prog) : firstElement(first), difference(diff) {
        progression = prog; // Инициализация поля progression данными из аргумента
        if (!isArithmeticProgression()) {
            throw InvalidArithmeticProgression("The provided array is not an arithmetic progression.");
        }
    }

    bool isArithmeticProgression() {
        if (progression.size() < 2) {
            return true;
        }

        int expectedDifference = progression[1] - progression[0];
        if (expectedDifference != difference) {
            return false;
        }

        for (size_t i = 2; i < progression.size(); ++i) {
            if (progression[i] - progression[i - 1] != expectedDifference) {
                return false;
            }
        }

        return true;
    }

    void printData() {
        cout << "First Element: " << firstElement << endl;
        cout << "Difference: " << difference << endl;
        cout << "Progression: ";
        for (int num : progression) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        vector<int> validProgression = { 1, 3, 5, 7, 9 };
        ArithmeticProgression validAP(1, 2, validProgression);
        validAP.printData();

        vector<int> invalidProgression = { 1, 3, 5, 8, 9 };
        ArithmeticProgression invalidAP(1, 2, invalidProgression);
    }
    catch (const InvalidArithmeticProgression& e) {
        cerr << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}