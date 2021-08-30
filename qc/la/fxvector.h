/**@file
 * @brief     LA fixed length Vector.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

#include <array>

#include "qc/la/fxvector_impl_generic.h"

namespace qc::la {


template<typename T, std::size_t SIZE, typename Impl=FxVectorImplGeneric>
class FxVector
{
public:
    using Storage = std::array<T, SIZE>;
    Storage s_;

    using size_type = Storage::size_type;
    using reference = Storage::reference;


public:
    FxVector() = default;
    FxVector(const FxVector&) = default;

    FxVector(std::initializer_list<T> list) {
        for (std::size_t pos = 0; const T v : list) {
            s_.at(pos++) = v;
        }
    }

    FxVector& operator=(const FxVector&) = default;

    constexpr size_type size() const noexcept {
        return s_.size();
    }

    constexpr reference operator[](size_type pos) {
        return s_[pos];
    }

    double length() const {
        return Impl::length(*this);
    }
};

} // namespace qc::la
