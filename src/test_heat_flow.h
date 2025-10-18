#pragma once

#include <array>

#include "heat_flow_base.h"

class Test_HeatFlow : public HeatFlow_Base{
private:
    std::array<double, 5> current_rod;

public:
    Test_HeatFlow(std::array<double, 5> rod);
    void tick() override; // No Op
    std::array<double, 5> get_current_rod() override;
};