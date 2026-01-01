#pragma once

#include <functional>
#include <vector>
#include <string>

namespace lemlib {

class AutonSelector {
public:
    using AutonRoutine = std::function<void()>;

    /**
     * @brief Initialize the autonomous selector UI
     * Must be called once during robot initialization
     */
    static void initialize();

    /**
     * @brief Add an autonomous routine to the selector
     * @param name Display name of the routine
     * @param routine Function pointer to the autonomous routine
     */
    static void addRoutine(const std::string& name, AutonRoutine routine);

    /**
     * @brief Get the currently selected autonomous routine
     * @return Function pointer to the selected routine
     */
    static AutonRoutine getSelectedRoutine();

    /**
     * @brief Get the name of the currently selected routine
     * @return Name of selected routine
     */
    static std::string getSelectedRoutineName();

    /**
     * @brief Handle button presses for selector navigation
     * Call this in your opcontrol or a dedicated task
     */
    static void handleInput();

    /**
     * @brief Clean up the selector
     */
    static void cleanup();

private:
    struct RoutineInfo {
        std::string name;
        AutonRoutine routine;
    };

    static std::vector<RoutineInfo> routines;
    static int selectedIndex;
    static bool initialized;
    
    static void updateDisplay();
};

} // namespace lemlib
