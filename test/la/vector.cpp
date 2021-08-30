/**@file
 * @brief     Test LA Vector.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#include <cstdlib>
#include <cassert>

#include "qc/la/fxvector.h"

static bool test_constructor()
{
    using namespace qc::la;

    FxVector<int, 2> fv1;
    fv1[0] = 3;
    fv1[1] = 4;
    FxVector<int, 2> fv2{3, 4};
    assert(fv1[0]==fv2[0] && fv1[1] == fv2[1]);


    return true;
}

static bool test_size()
{
    using namespace qc::la;

    FxVector<int, 3> fv;
    static_assert(fv.size() == 3);

    return true;
}

static bool test_length()
{
    using namespace qc::la;

    FxVector<int, 2> fv;
    fv[0] = 3;
    fv[1] = 4;
    double length = fv.length();
    assert(length == 5.0);

    return true;
}

using TestFun = bool (*)();

static TestFun tests[] = {
    test_constructor,
    test_size,
    test_length
};

int main(int, char**)
{
    for (auto test : tests) {
        if (!test()) return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
