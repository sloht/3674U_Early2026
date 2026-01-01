# Quick Start Guide: Autonomous Selector

## 30-Second Setup

### Step 1: Include the header in main.cpp
```cpp
#include "lemlib/auton_selector.hpp"
```

### Step 2: Initialize in `initialize()`
```cpp
void initialize() {
    // ... existing code ...
    
    lemlib::AutonSelector::initialize();
    lemlib::AutonSelector::addRoutine("Blue", auton_blue);
    lemlib::AutonSelector::addRoutine("Red", auton_red);
}
```

### Step 3: Use in `autonomous()`
```cpp
void autonomous() {
    auto routine = lemlib::AutonSelector::getSelectedRoutine();
    routine();
}
```

### Step 4: Define your routines
```cpp
void auton_blue() {
    chassis.moveToPose(24, 0, 0, 2000);
}

void auton_red() {
    chassis.moveToPose(24, 0, 180, 2000);
}
```

Done! 🎉

## What You Get

✅ **Display on VEX Brain Screen:**
```
Select Autonomous Routine
  > Blue
    Red
Selected: Blue
```

✅ **Compile & Run:**
- No errors
- Ready to download
- Fully functional

## Using the Advanced Version (Optional)

For more features:
```cpp
#include "lemlib/auton_selector_advanced.hpp"

void initialize() {
    static lemlib::AdvAutonSelector selector;
    selector.addRoutine("Blue Safe", auton_blue_safe);
    selector.addRoutine("Blue Aggressive", auton_blue_aggressive);
    selector.display();
}

void autonomous() {
    static lemlib::AdvAutonSelector selector;
    selector.getSelectedRoutine()();
}
```

## Documentation

- 📖 Full guide: [AUTON_SELECTOR_README.md](AUTON_SELECTOR_README.md)
- 💡 Examples: [src/auton_selector_examples.cpp](src/auton_selector_examples.cpp)
- 📋 Details: [IMPLEMENTATION_SUMMARY.md](IMPLEMENTATION_SUMMARY.md)

## Current Status

✅ **Code**: Compiled without errors
✅ **Integration**: Fully integrated into main.cpp
✅ **Examples**: Three example routines ready to use
✅ **Documentation**: Complete and ready to reference

## Ready to Build?

1. Download this code to your robot
2. Modify the routine names to match your strategy
3. Update the routine functions with your movements
4. Done!

---

**Need help?** Check the documentation files or the example routines in `src/auton_selector_examples.cpp`
