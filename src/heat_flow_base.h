#pragma once

#include <array>

class HeatFlow_Base {
public:
    virtual ~HeatFlow_Base() = default;
    virtual void tick() = 0;
    virtual std::array<double,5> get_current_rod() = 0;
};