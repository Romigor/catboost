#include <library/unittest/registar.h>

#include "spinlock.h"

Y_UNIT_TEST_SUITE(TSpinLock) {
    template <typename TLock>
    void TestLock() {
        TLock lock;
        UNIT_ASSERT(!lock.IsLocked());
        lock.Acquire();
        UNIT_ASSERT(lock.IsLocked());
        lock.Release();
        UNIT_ASSERT(!lock.IsLocked());

        UNIT_ASSERT(lock.TryAcquire());
        UNIT_ASSERT(lock.IsLocked());
        UNIT_ASSERT(!lock.TryAcquire());
        UNIT_ASSERT(lock.IsLocked());
        lock.Release();
        UNIT_ASSERT(!lock.IsLocked());
    }

    Y_UNIT_TEST(TSpinLock_IsLocked) {
        TestLock<TSpinLock>();
    }

    Y_UNIT_TEST(TAdaptiveLock_IsLocked) {
        TestLock<TAdaptiveLock>();
    }
}
