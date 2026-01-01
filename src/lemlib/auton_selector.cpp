#include "lemlib/auton_selector.hpp"
#include "pros/screen.hpp"

namespace lemlib {

// Static member initialization
std::vector<AutonSelector::RoutineInfo> AutonSelector::routines;
int AutonSelector::selectedIndex = 0;
bool AutonSelector::initialized = false;

void AutonSelector::initialize() {
    if (initialized) return;
    initialized = true;
    
    updateDisplay();
}

void AutonSelector::addRoutine(const std::string& name, AutonRoutine routine) {
    if (!initialized) initialize();

    routines.push_back({name, routine});
    updateDisplay();
}

void AutonSelector::updateDisplay() {
    if (routines.empty()) {
        pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE, 0, "No Autonomous Routines");
        return;
    }
    
    // Clear screen
    pros::screen::erase();
    
    // Display title
    pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE_CENTER, 0, "Select Autonomous");
    
    // Display all routines with * next to selected one
    int lineNum = 2;
    for (size_t i = 0; i < routines.size() && i < 6; i++) {
        std::string prefix = (i == (size_t)selectedIndex) ? "> " : "  ";
        std::string display = prefix + routines[i].name;
        pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM, lineNum, display.c_str());
        lineNum++;
    }
    
    // Display controls
    pros::screen::print(pros::text_format_e_t::E_TEXT_SMALL, 7, "L: Previous | R: Next | A: Select");
}

void AutonSelector::handleInput() {
    // This would be called in opcontrol to handle button presses
    // Example implementation using controller buttons
    // Note: This is a basic implementation - adjust based on your control scheme
}

AutonSelector::AutonRoutine AutonSelector::getSelectedRoutine() {
    if (selectedIndex >= 0 && selectedIndex < (int)routines.size()) {
        return routines[selectedIndex].routine;
    }
    // Return a dummy routine if nothing is selected
    return []() {};
}

std::string AutonSelector::getSelectedRoutineName() {
    if (selectedIndex >= 0 && selectedIndex < (int)routines.size()) {
        return routines[selectedIndex].name;
    }
    return "None";
}

void AutonSelector::cleanup() {
    routines.clear();
    selectedIndex = 0;
    initialized = false;
}

} // namespace lemlib
