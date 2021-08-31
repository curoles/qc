/**@file
 * @brief     LA fixed length Vector.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

#include <array>

#include "qc/la/scale.h"
#include "qc/la/fxvector_impl_generic.h"

namespace qc::la {

/// A _vector_ in Linear Algebra is just a list of numbers.
///
template<typename T, std::size_t SIZE, typename Impl=FxVectorImplGeneric>
class FxVector
{
public:
    using Storage = std::array<T, SIZE>;
    Storage data_;

    using size_type = Storage::size_type;
    using value_type = Storage::value_type;
    using reference = Storage::reference;
    using const_reference = Storage::const_reference;

    Scale<T> scale_;

    bool is_column_ = true;
    bool is_column() const noexcept { return is_column_; }
    bool is_row() const noexcept { return !is_column_; }

    /// Return true if it is _ket_ vector ∣𝒗⟩
    bool is_ket() const noexcept { return is_column_; }

    /// Return true if it is _bra_ vector ⟨𝒗∣
    bool is_bra() const noexcept { return !is_column_; }
    

public:
    FxVector() = default;
    FxVector(const FxVector&) = default;

    FxVector(std::initializer_list<T> list) {
        for (std::size_t pos = 0; const T v : list) {
            data_.at(pos++) = v;
        }
    }

    FxVector& operator=(const FxVector&) = default;

    /// Number of elements (in the list).
    constexpr size_type size() const noexcept {
        return data_.size();
    }

    /// Number of elements (in the list).
    constexpr size_type dimention() const noexcept {
        return size();
    }

    constexpr reference operator[](size_type pos) {
        return data_[pos];
    }

    constexpr const_reference operator[]( size_type pos ) const {
        return data_[pos];
    }

    void set_scale(bool exist = false, T new_scale_val = (T)1) {
        scale_.exist = exist;
        scale_.val = new_scale_val;
    }

    double length() const {
        return Impl::length(*this);
    }

    FxVector& add(const FxVector& other) {
        Impl::add(*this, other);
        return *this;
    }
};

} // namespace qc::la

template<typename T, std::size_t N, typename I>
qc::la::FxVector<T,N,I> operator+(
    const qc::la::FxVector<T,N,I>& a,
    const qc::la::FxVector<T,N,I>& b)
{
    auto res = a;
    res.add(b);
    return res;
}