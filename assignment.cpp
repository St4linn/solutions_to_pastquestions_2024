#include <iostream>
#include <string>
using namespace std;

class Questions {
public:
    // Question 2a: Check if a number is prime
    bool isPrime(int* num) {
        if (*num <= 1) return false;
        for (int i = 2; i * i <= *num; i++) {
            if (*num % i == 0) return false;
        }
        return true;
    }

    // Question 2b: Compute the sum of all elements in an array
    int sumOfArray(int* arr, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Question 3a: Implement bubble sort to sort an array
    void bubbleSort(int* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Question 3b: Read 10 numbers, compute their sum and average
    void sumAndAverage(float* sum, float* avg) {
        float numbers[10];
        *sum = 0;
        cout << "Enter 10 numbers: ";
        for (int i = 0; i < 10; i++) {
            cin >> numbers[i];
            *sum += numbers[i];
        }
        *avg = *sum / 10;
    }

    // Question 4a: Compute the length of a string using a function
    int stringLength(const char* str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // Question 4b: Find the position of a target value in an array using linear search
    int linearSearch(int* arr, int size, int target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1; // Not found
    }

    // Question 5a: Add two numbers using pointers
    int addNumbers(int* a, int* b) {
        return *a + *b;
    }

    // Question 5b: Check if a number is a palindrome
    bool isPalindrome(int* num) {
        int original = *num; // Store the original number
        int reversed = 0, temp = original;
        while (temp != 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        return (original == reversed);
    }

    // Question 6a: Student structure and average marks calculation
    struct Student {
        string name;
        int age;
        float totalMarks;
    };

    void studentInfo() {
        Student students[2];
        cin.ignore(); // Clear the buffer before using getline
        for (int i = 0; i < 2; i++) {
            cout << "Enter name: ";
            getline(cin, students[i].name);
            cout << "Enter age: ";
            cin >> students[i].age;
            cout << "Enter total marks: ";
            cin >> students[i].totalMarks;
            cin.ignore(); // Clear the buffer after numeric input
        }
        float averageMarks = (students[0].totalMarks + students[1].totalMarks) / 2;
        cout << "Average marks: " << averageMarks << endl;
    }

    // Question 6b: Check if a number is odd, even, positive, or negative
    void checkNumber(int* num) {
        if (*num > 0) {
            cout << "Positive ";
        } else if (*num < 0) {
            cout << "Negative ";
        } else {
            cout << "Zero ";
        }
        if (*num % 2 == 0) {
            cout << "Even" << endl;
        } else {
            cout << "Odd" << endl;
        }
    }
};

int main() {
    Questions q;

    // Example usage of the functions
    int num = 29;
    cout << "Is prime? " << (q.isPrime(&num) ? "Yes" : "No") << endl;

    int arr[] = {3, 1, 4, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of array: " << q.sumOfArray(arr, size) << endl;

    q.bubbleSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    float sum, avg;
    q.sumAndAverage(&sum, &avg);
    cout << "Sum: " << sum << ", Average: " << avg << endl;

    const char* str = "Hello";
    cout << "String length: " << q.stringLength(str) << endl;

    int target = 4;
    cout << "Linear search position: " << q.linearSearch(arr, size, target) << endl;

    int a = 5, b = 10;
    cout << "Sum of numbers: " << q.addNumbers(&a, &b) << endl;

    int palindromeNum = 121;
    cout << "Is palindrome? " << (q.isPalindrome(&palindromeNum) ? "Yes" : "No") << endl;

    q.studentInfo();

    int checkNum = -7;
    q.checkNumber(&checkNum);

    return 0;
}
