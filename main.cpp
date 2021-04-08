#include <iostream>
#include <vector>

#include "ProgressBar.h"
#include "RandomEngine.h"
#include "TextColor.h"
#include "Walltime.h"

using namespace std;
using namespace stdmt;

int main() {
    // Testing color
    cout << TextColor{ColorId::green} << "Hello, World!\n" << TextColor{};

    // Testing walltime and progress bar
    Walltime wt;
    wt.start();
    const int N = 100'000'000;
    ProgressBar pb{N};
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        vec.push_back(i);
        pb++;
    }
    wt.stop();
    cout << wt << "\n";

    // Testing random numbers
    const int M = 5;
    RandomEngine re;
    for (int i = 0; i < M; i++) {
        cout << "Random int [2, 7]: " << re.getRandInt(2, 7) << "\n";
    }
    for (int i = 0; i < M; i++) {
        cout << "Random char ['a', 'e']: " << re.getRandChar('a', 'e') << "\n";
    }

    return 0;
}
