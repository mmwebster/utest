/*!
 * @copright
 * Copyright (c) 2017, Tymoteusz Blazejczyk
 * All rights reserved.
 *
 * @copright
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * @copright
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * @copright
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * @copright
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * @copright
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file utest/test_message/test_assert_less_than_or_equal.hpp
 *
 * @brief Test message interface
 */

#ifndef UTEST_TEST_MESSAGE_TEST_ASSERT_LESS_THAN_OR_EQUAL_HPP
#define UTEST_TEST_MESSAGE_TEST_ASSERT_LESS_THAN_OR_EQUAL_HPP

#include <utest/test_message/test_assert_compare.hpp>

namespace utest {
namespace test_message {

class TestAssertLessThanOrEqual : public TestAssertCompare {
private:
    friend class utest::TestAssert;

    TestAssertLessThanOrEqual(const TestAssert& test_assert,
            const TestValue& lhs, const TestValue& rhs) noexcept;
};

inline
TestAssertLessThanOrEqual::TestAssertLessThanOrEqual(
        const TestAssert& test_assert, const TestValue& lhs,
        const TestValue& rhs) noexcept :
    TestAssertCompare{TestMessage::TEST_ASSERT_LESS_THAN_OR_EQUAL,
        test_assert, lhs, rhs}
{ }

template<> inline auto
get(const TestMessage& msg) noexcept -> const TestAssertLessThanOrEqual& {
    return reinterpret_cast<const TestAssertLessThanOrEqual&>(msg);
}

}
}

#endif /* UTEST_TEST_MESSAGE_TEST_ASSERT_LESS_THAN_OR_EQUAL_HPP */