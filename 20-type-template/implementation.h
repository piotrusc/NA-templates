#pragma once
#include <cstddef>
#include <utility>
#include <boost/optional.hpp>


template<typename T>
class container_wrapper{
public:
    container_wrapper() = default;

    container_wrapper(T arg): value(std::move(arg)){
    }

    container_wrapper(const container_wrapper &) = default;

    container_wrapper(container_wrapper &&) = default;

    container_wrapper & operator=(const container_wrapper &) = default;

    container_wrapper & operator=(container_wrapper &&) = default;

    std::size_t size() const{
        return value.size();
    }
private:
    T value;
};

template<typename T>
class container_wrapper<boost::optional<T>>{
public:
    container_wrapper() = default;

    container_wrapper(boost::optional<int> arg): value(std::move(arg)){
    }

    container_wrapper(const container_wrapper &) = default;

    container_wrapper(container_wrapper &&) = default;

    container_wrapper & operator=(const container_wrapper &) = default;

    container_wrapper & operator=(container_wrapper &&) = default;

    std::size_t size() const{
        return value ? 1 : 0;
    }
private:
    boost::optional<T> value;
};

