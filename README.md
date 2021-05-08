# stdmt

> Useful C++ classes and functionality.

Every class and function are placed inside `namespace stdmt`. For usage only the header files are needed. Examples are given as comments in the header files and in *main.cpp*.

Classes:
- `ProgressBar`: Show simple progress bar in terminal. 
- `RandomEngine`: Generate random numbers in wanted range.
- `TextColor`: Give the text printed in terminal color. Only implementet for Windows and Linux.
- `Walltime`: Simple timer.
- `bitmap_image`:  [C++ Bitmap Library](http://www.partow.net/programming/bitmap/index.html)

Useful functions:
- `utilities_stdmt.h`

All of the code is based on the C++ Standard Library
- [C++ Standard Library headers](https://en.cppreference.com/w/cpp/header)

Other great C++ libraries:
- [Boost](https://www.boost.org/)
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

---

## Git Tools - Submodules
https://git-scm.com/book/en/v2/Git-Tools-Submodules

```
# Add submodule
git submodule add https://github.com/martinty/stdmt.git
git add .
git commit -m "Add submodule stdmt"
git push origin master

# Update submodule to latest commit
git submodule update --remote
```
