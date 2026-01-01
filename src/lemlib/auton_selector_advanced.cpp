#include "lemlib/auton_selector_advanced.hpp"
#include "pros/screen.hpp"

namespace lemlib {

AdvAutonSelector::AdvAutonSelector()
    : selectedIndex(0), displayed(false), mainContainer(nullptr), 
      titleLabel(nullptr), descriptionLabel(nullptr), buttonContainer(nullptr) {
}

AdvAutonSelector::~AdvAutonSelector() {
    hide();
}

void AdvAutonSelector::addRoutine(const std::string& name, AutonRoutine routine) {
    routines.push_back({name, routine});
    if (displayed) {
        createButtons();
        updateDisplay();
    }
}

void AdvAutonSelector::display() {
    if (displayed) return;
    displayed = true;
    
    updateDisplay();
}

void AdvAutonSelector::createButtons() {
    // Buttons are displayed on screen, no need to create LVGL objects
    // This will be done in updateDisplay
}

void AdvAutonSelector::handleButtonClick(void* e) {
    // This handler would be called by LVGL, but we're using screen-based display instead
}

void AdvAutonSelector::updateDisplay() {
    if (!displayed) return;

    pros::screen::erase();
    
    // Display title
    pros::screen::print(pros::text_format_e_t::E_TEXT_LARGE_CENTER, 0, "Select Autonomous Routine");
    
    // Display all available routines
    int lineNum = 2;
    for (size_t i = 0; i < routines.size() && lineNum < 7; i++) {
        std::string prefix = (i == (size_t)selectedIndex) ? "> " : "  ";
        std::string display = prefix + routines[i].name;
        
        // Highlight selected routine
        if (i == (size_t)selectedIndex) {
            pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM, lineNum, display.c_str());
        } else {
            pros::screen::print(pros::text_format_e_t::E_TEXT_MEDIUM, lineNum, display.c_str());
        }
        lineNum++;
    }
    
    // Display currently selected
    std::string selectedStr = "Selected: " + routines[selectedIndex].name;
    pros::screen::print(pros::text_format_e_t::E_TEXT_SMALL, 7, selectedStr.c_str());
}

void AdvAutonSelector::hide() {
    displayed = false;
    buttons.clear();
}

AdvAutonSelector::AutonRoutine AdvAutonSelector::getSelectedRoutine() const {
    if (selectedIndex >= 0 && selectedIndex < (int)routines.size()) {
        return routines[selectedIndex].routine;
    }
    return []() {};
}

std::string AdvAutonSelector::getSelectedRoutineName() const {
    if (selectedIndex >= 0 && selectedIndex < (int)routines.size()) {
        return routines[selectedIndex].name;
    }
    return "None";
}

} // namespace lemlib
