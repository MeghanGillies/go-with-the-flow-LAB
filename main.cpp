#include <iostream>

#include "src/heat_flow_config.h"
#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"
#include "src/input_validator.h"

int main() {
    InputValidator validator;
    std::map<int,double> sources_sinks = {};

    std::cout << "Welcome to the Heat flow simulator!\n"
              <<  "Here you can simulate the one-dimensional "
              << "flow of heat in a thin rod.\n\n";

    std::string prompt = "Please enter the initial temperature of the rod: ";
    std::string error_message = "That is not a valid temperature. Try again.";
    double initial_temp = validator.validate(prompt, error_message);

    prompt = "How many sources/sinks would you like to have? (1-4): ";
    error_message = "That is not a valid amount of sources/sinks. Try Again.";
    int num_sources_sinks = validator.validate(5, 0,prompt, error_message);

    for (int i = 0; i < num_sources_sinks; i++) {
        bool valid_index = false;
        int index;

        while (!valid_index) {
            prompt = "What index is your source/sink? (0-4): ";
            error_message = "That is not a valid index. Try again.";
            index = validator.validate(5, -1, prompt, error_message);

            try { // Index is already a Source/Sink
                sources_sinks.at(index);
                std::cout << "\nYou already have a source/sink at this index. Please try again.\n";

            } catch (const std::out_of_range &) { // Index is NOT a Source/Sink
                valid_index = true;
            }
        }

        prompt = "What is the temperature of your source/sink? ";
        error_message = "That is not a valid temperature. Try again.";
        double temp = validator.validate(prompt, error_message);

        sources_sinks.insert({index, temp});
    }

    prompt = "What value would you like to use for the constant K (between 0-1): ";
    error_message = "That is not a valid K value. Try Again.";
    double k = validator.validate(1.0, 0.0,prompt, error_message);

    prompt = "How many steps would you like to simulate? (5-10): ";
    error_message = "That is not a valid number of steps. Try Again.";
    int num_steps = validator.validate(11, 4,prompt, error_message);

    std::cout << "\nStarting simulation...\n\n";

    HeatFlow_Config config(initial_temp, sources_sinks, k);
    HeatFlow heat_flow(config);
    HeatFlow_Printer printer(&heat_flow);

    for (int i = 0; i < num_steps; i++) {
        std::cout << printer.pretty_print();
        heat_flow.tick();
    }

    std::cout << "\nThank you for using the Heat Flow Simulator!\n";

    return 0;
}