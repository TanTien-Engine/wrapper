#pragma once

#include <memory>

namespace wrapper
{

template<typename T>
struct Proxy
{
    ~Proxy() {}

    std::shared_ptr<T> obj = nullptr;
};

}