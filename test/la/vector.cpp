/**@file
 * @brief     Test LA Vector.
 * @author    Igor Lesik 2021
 * @copyright Igor Lesik 2021
 *
 */
#include <cstdlib>
#include <cassert>

#include "qc/la/fxvector.h"
#include "qc/la/vector.h"


static bool test_constructor()
{
    using namespace qc::la;

    FxVector<int, 2> fv1;
    fv1[0] = 3;
    fv1[1] = 4;
    FxVector<int, 2> fv2{3, 4};
    assert(fv1[0]==fv2[0] && fv1[1] == fv2[1]);

    Vector<int> v3{3, 4, 5};
    assert(v3[0] == 3 && v3[1] == 4 && v3[2] == 5);

    return true;
}

static bool test_size()
{
    using namespace qc::la;

    FxVector<int, 3> fv;
    static_assert(fv.size() == 3);

    Vector<int> v{3, 4, 5};
    assert(v.size() == 3);

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

    Vector<int> v{3, 4};
    assert(v.length() == 5.0);

    return true;
}

static bool test_scale()
{
    using namespace qc::la;

    FxVector<int, 2> fv{3, 4};
    fv.set_scale(true, 2);
    assert(fv.length() == (5.0 * 2));

    Vector<int> v{3, 4};
    v.set_scale(true, 2);
    assert(v.length() == (5.0 * 2));

    return true;
}

static bool test_add()
{
    using namespace qc::la;

    FxVector<int, 3> a{3, 4, 5};
    FxVector<int, 3> b{6, 7, 8};

    FxVector<int, 3> c = a + b;
    assert(c[0]==9 && c[1]==11 && c[2]==13);

    a.set_scale(true, 2);
    b.set_scale(true, 3);
    c = a + b;
    assert(c[0]==9 && c[1]==11 && c[2]==13
        && c.scale_.exist && c.scale_.val == 6);

    return true;
}

using TestFun = bool (*)();

static TestFun tests[] = {
    test_constructor,
    test_size,
    test_length,
    test_scale,
    test_add
};

int main(int, char**)
{
    for (auto test : tests) {
        if (!test()) return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
