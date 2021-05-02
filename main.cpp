#include <iostream>
#include <vector>

#include "ProgressBar.h"
#include "RandomEngine.h"
#include "TextColor.h"
#include "Walltime.h"
#include "utilities_stdmt.h"

using namespace std;
using namespace stdmt;

int main() {
    // Testing color
    cout << TextColor{ColorId::green} << "Hello, World!\n" << TextColor{};

    // Testing walltime and progress bar
    Walltime wt;
    wt.start();
    const int N = 20'000'000;
    ProgressBar pb{N};
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        vec.push_back(i);
        pb++;
    }
    wt.stop();
    cout << wt << "\n";

    // Testing random numbers
    const int M = 2;
    RandomEngine re;
    for (int i = 0; i < M; i++) {
        cout << "Random int [2, 7]: " << re.getRandInt(2, 7) << "\n";
    }
    for (int i = 0; i < M; i++) {
        cout << "Random char ['a', 'e']: " << re.getRandChar('a', 'e') << "\n";
    }

    // Test input from user
    string str = getInput(string{"A"}, string{"zzzz"}, "String input");
    cout << str << endl;

    return 0;
}
