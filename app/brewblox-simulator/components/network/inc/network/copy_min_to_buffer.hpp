#pragma once
#include <algorithm>

template <typename InputIt, typename SourceLen, typename T, std::size_t size>
void copy_min_to_buffer(InputIt source, SourceLen source_length, T (&target)[size])
{
    auto to_copy = std::min(static_cast<std::size_t>(source_length), size);
    std::copy_n(source, to_copy, target);
}
