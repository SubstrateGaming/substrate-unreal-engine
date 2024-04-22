#pragma once
#include "types.h"
#include "rpc_types.h"

namespace substrate
{
   // TODO: Introduce crypto namespace?
   class LIB_SUBSTRATE_EXPORT ICrypto
   {
   public:
      virtual ~ICrypto() = default;

      // TODO: Move
      struct secret_pair
      {
         bytes key;
         bytes nonce; // for sr25519
      };

      // TODO: Move
      struct key_pair
      {
         bytes public_key;
         secret_pair secret;
      };

      [[nodiscard]] virtual key_pair make_keypair(const bytes &seed) const = 0;
      [[nodiscard]] virtual bytes sign(const bytes &message, const key_pair &key_pair) const = 0;
      [[nodiscard]] virtual bool verify(const bytes &message, const bytes &signature, const bytes &public_key) const = 0;
   };

   [[nodiscard]] LIB_SUBSTRATE_EXPORT Crypto make_crypto(substrate::rpc::KeyType provider);
   [[nodiscard]] LIB_SUBSTRATE_EXPORT Crypto make_crypto_ed25519();
   [[nodiscard]] LIB_SUBSTRATE_EXPORT Crypto make_crypto_sr25519();
   [[nodiscard]] LIB_SUBSTRATE_EXPORT Crypto make_crypto_secp256k1();
   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes pbkdf2_hmac_sha512(uint32_t derived_key_length, const substrate::bytes& password, const substrate::bytes& salt, uint32_t iteration_count);

   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes get_public_key(const std::string &address);
   [[nodiscard]] LIB_SUBSTRATE_EXPORT substrate::bytes get_public_key_with_network(const std::string &address, uint16_t &network);
   [[nodiscard]] LIB_SUBSTRATE_EXPORT std::string get_address(const substrate::bytes &bytes, uint16_t ss58_prefix = 42);

}
