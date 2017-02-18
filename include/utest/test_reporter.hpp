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
 * @file utest/test_repoter.hpp
 *
 * @brief Test reporter interface
 */

#ifndef UTEST_TEST_REPORTER_HPP
#define UTEST_TEST_REPORTER_HPP

#include <utest/test_span.hpp>
#include <utest/test_string.hpp>
#include <utest/test_color.hpp>
#include <utest/test_value.hpp>

#include <type_traits>

namespace utest {

class TestMessage;
class TestWriter;

class TestReporter {
public:
    template<typename T>
    using enable_signed = typename std::enable_if<
            std::is_integral<T>::value && std::is_signed<T>::value
        , int>::type;

    template<typename T>
    using enable_unsigned = typename std::enable_if<
            std::is_integral<T>::value && std::is_unsigned<T>::value
        , unsigned int>::type;

    using TestWriters = TestSpan<TestWriter*>;

    static TestReporter& get_default() noexcept;

    TestReporter() noexcept;

    TestReporter(const TestWriters& test_writers) noexcept;

    virtual void report(const TestMessage& test_message) noexcept = 0;

    virtual ~TestReporter() noexcept;

    void color(bool enable) noexcept;
protected:
    template<typename T, typename... Args>
    void write(const T& value, const Args&... args) noexcept;

    void write() noexcept;

    void color(TestColor c) noexcept;
private:
    void write_ex(std::intmax_t value) noexcept;

    void write_ex(std::uintmax_t value) noexcept;

    void write_ex(TestValue::Type value) noexcept;

    void write_ex(const TestValue& value) noexcept;

    void write_ex(const TestString& value) noexcept;

    void write_ex(const void* ptr) noexcept;

    template<TestSize N>
    void write_ex(const char (&str)[N]) noexcept;

    template<typename T, enable_signed<T> = 0>
    void write_ex(T value) noexcept;

    template<typename T, enable_unsigned<T> = 0>
    void write_ex(T value) noexcept;

    TestWriters m_writers{};
};

inline
TestReporter::TestReporter(const TestWriters& test_writers) noexcept :
    m_writers{test_writers}
{ }

template<typename T, TestReporter::enable_signed<T>> void
TestReporter::write_ex(T value) noexcept {
    write_ex(std::intmax_t(value));
}

template<typename T, TestReporter::enable_unsigned<T>> void
TestReporter::write_ex(T value) noexcept {
    write_ex(std::uintmax_t(value));
}

template<TestSize N> void
TestReporter::write_ex(const char (&str)[N]) noexcept {
    write_ex(TestString{str});
}


template<typename T, typename... Args> void
TestReporter::write(const T& value, const Args&... args) noexcept {
    write_ex(value);
    write(args...);
}

inline void
TestReporter::write() noexcept { }

}

#endif /* UTEST_TEST_REPORTER_HPP */
