#include "Math.h"

#include <ctime>
#include <stdexcept>
#include <string>

namespace mm {

RandomSpinGenerator::RandomSpinGenerator(unsigned long seed /* = 0 */)
    : m_rng(((seed == 0) ? std::time(NULL) : seed)), m_unif(0.0, 1.0) {}

}  //  end namespace 'mm'
