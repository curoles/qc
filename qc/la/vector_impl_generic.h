/**@file
 * @brief     LA Vector generic implementation.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

#include <cmath>

namespace qc::la {


class VectorImplGeneric
{
public:
    template<typename V>
    static double length(const V& v) {
        double l{0.0};
        for (const auto& el : v.data_) {
            l += el * el;
        }
        return std::sqrt(l) * v.scale_.val;
    }
};

} // namespace qc::la
