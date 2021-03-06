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
 * @file tests/color.cpp
 *
 * @brief Main implementation
 */

#include <utest/utest.hpp>
#include <utest/test_color.hpp>

using namespace utest;

static TestRunner g([] (TestSuite& test_suite) {
    test_suite.name("color").run([] (TestCase& test_case) {
        test_case.name("ansi escape codes").run([] (TestParams& p) {
            TestAssert{p}.equal("\x1B[30m", ansi_escape_code(TestColor::BLACK));
            TestAssert{p}.equal("\x1B[31m", ansi_escape_code(TestColor::RED));
            TestAssert{p}.equal("\x1B[32m", ansi_escape_code(TestColor::GREEN));
            TestAssert{p}.equal("\x1B[33m", ansi_escape_code(TestColor::YELLOW));
            TestAssert{p}.equal("\x1B[34m", ansi_escape_code(TestColor::BLUE));
            TestAssert{p}.equal("\x1B[35m", ansi_escape_code(TestColor::MAGENTA));
            TestAssert{p}.equal("\x1B[36m", ansi_escape_code(TestColor::CYAN));
            TestAssert{p}.equal("\x1B[37m", ansi_escape_code(TestColor::WHITE));
            TestAssert{p}.equal("\x1B[39m", ansi_escape_code(TestColor::DEFAULT));

            int invalid_code = -1;
            TestAssert{p}.equal("", ansi_escape_code(TestColor(invalid_code)));
        });
    });
});
