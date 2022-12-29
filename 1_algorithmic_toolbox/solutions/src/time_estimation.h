#include <chrono>
#include <utility>

typedef std::chrono::high_resolution_clock::time_point TimeVar;

template <typename T>
auto timeCount(T time_)
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(time_).count();
}

auto timeNow()
{
    return std::chrono::high_resolution_clock::now();
}

template <typename F, typename... Args>
auto funcTime(F func_temp, Args &&...args)
{
    TimeVar t1 = timeNow();
    auto res = func_temp(std::forward<Args>(args)...);
    return timeCount(timeNow() - t1);
}