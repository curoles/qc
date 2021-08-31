/**@file
 * @brief     Vector scalar scale.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#pragma once

namespace qc::la
{

template<typename T>
struct Scale
{
    bool exist = false;
    T val = (T)1;
};

}