#include "sha512.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include "gen_random.hpp"
#include <boost/multiprecision/cpp_bin_float.hpp>

int main()
{
	constexpr const std::uint8_t message[] = "Hello World!";
	cryptb::sha512::digest_t hash_bytes;
	{
		cryptb::sha512 hash;
		hash.update(message, sizeof(message) - 1);
		hash_bytes = hash.digest();
	}
	for (const std::uint8_t& byte_elem : hash_bytes)
	{
		std::ostringstream num_as_str;
		num_as_str << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte_elem);
		std::cout << num_as_str.str() << " ";
	}
	std::cout << std::endl;
	return 0;
}
