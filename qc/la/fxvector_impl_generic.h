/**@file
 * @brief     LA fixed length Vector generic implementation.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

#include <cmath>

namespace qc::la {


class FxVectorImplGeneric
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

    template<typename V>
    static void add(V& a, const V& b) {
        static_assert(a.size() == b.size());
        assert(a.is_ket() == b.is_ket());
        for (std::size_t pos = 0; pos < a.size(); ++pos) {
            a[pos] += b[pos];
        }

        if (b.scale_.exist) {
            a.scale_.exist = true;
            a.scale_.val = b.scale_.val * a.scale_.val;
        }
    }

};

} // namespace qc::la
