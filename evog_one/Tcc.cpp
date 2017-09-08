/* 
* Tcc.cpp
*/

#include "Tcc.h"

//==============//
//=== CONSTS ===//
//==============//

const Tcc::clock_s Tcc::CLOCK_OFF     = {Tcc::OFF, 0};
const Tcc::clock_s Tcc::CLOCK_DIV1    = {Tcc::DIV1, 0.002};
const Tcc::clock_s Tcc::CLOCK_DIV2    = {Tcc::DIV2, 0.0041};
const Tcc::clock_s Tcc::CLOCK_DIV4    = {Tcc::DIV4, 0.0082};
const Tcc::clock_s Tcc::CLOCK_DIV8    = {Tcc::DIV8, 0.0164};
const Tcc::clock_s Tcc::CLOCK_DIV64   = {Tcc::DIV64, 0.1311};
const Tcc::clock_s Tcc::CLOCK_DIV256  = {Tcc::DIV256, 0.5243};
const Tcc::clock_s Tcc::CLOCK_DIV1024 = {Tcc::DIV1024, 2.0972};
const Tcc::clock_s Tcc::CLOCK_EVCH0   = {Tcc::EVCH0, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH1   = {Tcc::EVCH1, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH2   = {Tcc::EVCH2, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH3   = {Tcc::EVCH3, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH4   = {Tcc::EVCH4, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH5   = {Tcc::EVCH5, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH6   = {Tcc::EVCH6, 0};
const Tcc::clock_s Tcc::CLOCK_EVCH7   = {Tcc::EVCH7, 0};