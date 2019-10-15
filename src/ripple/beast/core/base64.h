#ifndef BEAST_BASE64_H_INCLUDED
#define BEAST_BASE64_H_INCLUDED

#include <beast/include/boost/beast/core/detail/base64.hpp>
#include <iostream>

namespace boost {
namespace beast {
namespace detail {

//namespace base64 {

std::string
base64_encode(std::uint8_t const* data, std::size_t len);


std::string
base64_encode(string_view s);


std::string
base64_decode(string_view data);

//} //base64
} //detail
} //beast
} //boost

#endif