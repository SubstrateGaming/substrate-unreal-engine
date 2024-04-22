#pragma once
#include "types.h"

namespace substrate::hash
{
   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes sha256(const substrate::bytes& input);
   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes sha512(const substrate::bytes& input);
   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes blake2(const substrate::bytes& input, size_t size = 128, const substrate::bytes& key = {});
}
