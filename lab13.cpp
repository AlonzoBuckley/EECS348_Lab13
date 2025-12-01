/* Q1: There is a fault in the program program because the loop starss at 1, it 
wont examine [0] which is the first lecture.
Q2: a test case does not exist becuase of the initialization of i = 1,
this is impossible because the faulty loop will always cause the fault to executre.
*/


#include <iostream>
#include <vector>

bool fail_lecture(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    // Original erroneous function
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}


bool fail_lecture_correct(const std::vector<int>& attendance_records) {
    int absent_count = 0;
    // Corrected function
    for (int i = 0; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

void run_test(const std::vector<int>& record, const std::string& name) {
    bool actual   = fail_lecture(record);
    bool expected = fail_lecture_correct(record);

    std::cout << name << " : ";
    for (int v : record) std::cout << v << ' ';
    std::cout << "\n  expected = " << expected
              << ", actual = " << actual << "\n\n";
}

int main() {
    // Q3: executes fault, but no error state
    run_test({1,1,1,1,1,1,1,1,1,1}, "TC3");

    // Q4: error state but no failure
    run_test({0,0,0,0,1,1,1,1,1,1}, "TC4");

    // Q5: failure
    run_test({0,0,0,1,1,1,1,1,1,1}, "TC5");

    return 0;
}
