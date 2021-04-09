#pragma once

// Martin Tysseland - 08.04.2021
// Class to calculate walltime duration
// Example:
// {
//     Walltime wt;
//     wt.start();
//     // Do work ...
//     wt.stop();
//     cout << wt << "\n";
// }

#include <chrono>
#include <ostream>

namespace stdmt {

class Walltime {
   private:
    std::chrono::steady_clock::time_point startTime;
    double duration = 0;

   public:
    Walltime() = default;
    ~Walltime() = default;

    // start() also restart the timer
    void start() {
        duration = 0;
        startTime = std::chrono::steady_clock::now();
    }

    // Update duration. Can stack multiple stop() after each other
    void stop() {
        const auto endTime = std::chrono::steady_clock::now();
        const auto diffTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(endTime -
                                                                  startTime);
        duration = diffTime.count() / 1000.0;
    }
    double getDuration() const { return duration; }
};

inline std::ostream& operator<<(std::ostream& os, const Walltime& wt) {
    return os << "Walltime: " << wt.getDuration() << " [s]";
}

}  // namespace stdmt
