#pragma once
#include <type_traits>
#include <utility>

namespace structbuf
{
    /**
     * 基于编译期常量的作为范围，循环执行某指定函数
     * @param(f): 可调用对象，签名为auto F<integral i>()
     */
    template <auto Start, auto End, typename F>
    inline constexpr void constexpr_for(F &&f)
    {
        if constexpr (Start < End)
        {
            f.template operator()<Start>();
            constexpr_for<Start + 1, End>(std::forward<F>(f));
        }
    }
}