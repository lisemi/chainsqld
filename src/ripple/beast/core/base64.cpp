#include <beast/include/boost/beast/core/detail/base64.hpp>
#include <iostream>

namespace boost {
namespace beast {
namespace detail {

//namespace base64 {

std::string
base64_encode(
    std::uint8_t const* data,
    std::size_t len)
{
    std::string dest;
    dest.resize(base64::encoded_size(len));
    dest.resize(base64::encode(&dest[0], data, len));
    return dest;
}

std::string
base64_encode(string_view s)
{
    return base64_encode (reinterpret_cast <
        std::uint8_t const*> (s.data()), s.size());
}

std::string
base64_decode(string_view data)
{
    std::string dest;
    dest.resize(base64::decoded_size(data.size()));
    auto const result = base64::decode(
        &dest[0], data.data(), data.size());
        dest.resize(result.first);
    return dest;
}

//} //base64
} //detail
} //beast
} //boost