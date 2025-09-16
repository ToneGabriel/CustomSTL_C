# PROJECT

**Version: 0.0.0-alpha**

**PROJECT** description

---

## Contents

<details>
<summary><b>Highlights</b></summary>

- Some highlight 1
- Some highlight 2
- Some highlight 3

</details>
<!-- END Highlights -->

<details>
<summary><b>Usage</b></summary>

PROJECT short usage description

```C++
#include <iostream>

int main()
{
    return 0;
}
```

</details>
<!-- END Usage -->

<details>
<summary><b>Headers</b></summary>

- `header_1.h`
- `header_2.h`
- `header_3.h`

</details>
<!-- END C Headers -->

---

## Requirements

- **C Compiler**: C99 compliant
- **C++ Compiler**: C++20 or newer
- **Build System**: CMake (≥ 3.22.1), Ninja  
- **Testing Frameworks**:  
  - [GoogleTest](https://github.com/google/googletest) (auto fetched via CMake)  
  - [Unity](https://github.com/ThrowTheSwitch/Unity) (auto fetched via CMake)  

---

## Installation & Build

```bash
# Clone the repository
git clone https://github.com/ToneGabriel/PROJECT.git
cd PROJECT

# Create a build directory
cmake -G "Ninja" -B build

# Build the project
cmake --build build

# Run tests
ctest --test-dir build
```

Or simply run the script `scripts/RUN_TESTS` and the build is done automatically.   
The results can be found in `build/Testing/Temporary` folder.
