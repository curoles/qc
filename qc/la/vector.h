/**@file
 * @brief     LA Vector.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

#include <vector>

#include "qc/la/scale.h"
#include "qc/la/vector_impl_generic.h"

namespace qc::la {

template<typename T, typename Impl=VectorImplGeneric>
class Vector
{
public:
    using Storage = std::vector<T>;
    Storage data_;

    using size_type = Storage::size_type;
    using reference = Storage::reference;

    Scale<T> scale_;

public:
    Vector() = default;
    Vector(const Vector&) = default;

    Vector(std::initializer_list<T> list) {
        for (const T v : list) {
            data_.push_back(v);
        }
    }

    Vector& operator=(const Vector&) = default;

    size_type size() const noexcept {
        return data_.size();
    }

    constexpr reference operator[](size_type pos) {
        return data_[pos];
    }

    void set_scale(bool exist = false, T new_scale_val = (T)1) {
        scale_.exist = exist;
        scale_.val = new_scale_val;
    }

    double length() const {
        return Impl::length(*this);
    }
};

} // namespace qc::la
