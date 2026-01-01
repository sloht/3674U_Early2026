#pragma once

#include <functional>
#include <vector>
#include <string>

namespace lemlib {

/**
 * @brief Advanced autonomous selector with full liblvgl UI support
 * 
 * This class provides a complete autonomous routine selector using the VEX screen.
 * It features:
 * - Interactive button selection with visual feedback
 * - Real-time UI updates
 * - Simple to use interface
 * 
 * Usage:
 * @code
 * void initialize() {
 *     // Create and initialize selector
 *     AdvAutonSelector selector;
 *     selector.addRoutine("Blue Alliance", auton_blue);
 *     selector.addRoutine("Red Alliance", auton_red);
 *     selector.addRoutine("Skills", auton_skills);
 *     selector.display();
 * }
 * 
 * void autonomous() {
 *     auto routine = selector.getSelectedRoutine();
 *     routine();
 * }
 * @endcode
 */
class AdvAutonSelector {
public:
    using AutonRoutine = std::function<void()>;

    /**
     * @brief Constructor - creates an autonomous selector instance
     */
    AdvAutonSelector();

    /**
     * @brief Destructor - cleans up UI resources
     */
    ~AdvAutonSelector();

    /**
     * @brief Add an autonomous routine to the selector
     * @param name Display name of the routine
     * @param routine Function pointer to the autonomous routine
     */
    void addRoutine(const std::string& name, AutonRoutine routine);

    /**
     * @brief Display the selector UI on the brain screen
     * Should be called in initialize() to show the selector before competition
     */
    void display();

    /**
     * @brief Hide the selector UI
     */
    void hide();

    /**
     * @brief Get the currently selected autonomous routine
     * @return Function pointer to the selected routine
     */
    AutonRoutine getSelectedRoutine() const;

    /**
     * @brief Get the name of the currently selected routine
     * @return Name of selected routine
     */
    std::string getSelectedRoutineName() const;

    /**
     * @brief Get the index of the selected routine
     * @return Index of selected routine (0-based)
     */
    int getSelectedIndex() const { return selectedIndex; }

    /**
     * @brief Get the total number of routines
     * @return Number of registered routines
     */
    size_t getRoutineCount() const { return routines.size(); }

private:
    struct RoutineInfo {
        std::string name;
        AutonRoutine routine;
    };

    std::vector<RoutineInfo> routines;
    int selectedIndex;
    bool displayed;
    
    // UI components (not used in simpler implementation)
    void* mainContainer;
    void* titleLabel;
    void* descriptionLabel;
    void* buttonContainer;
    std::vector<void*> buttons;

    // Callbacks
    static void handleButtonClick(void* e);
    void updateDisplay();
    void createButtons();
};

} // namespace lemlib
