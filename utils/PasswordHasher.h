#pragma once

#include <string>
#include <cstdint>

/**
 * PasswordHasher - A SHA-256 based password hashing utility
 *
 * Provides secure password hashing with salt support using
 * a custom SHA-256 implementation (no external dependencies).
 */
class PasswordHasher {
public:
    /**
     * Hash a password with an auto-generated random salt.
     * @param password  Plain-text password to hash
     * @return          Salted hash string in format "SALT$HASH"
     */
    static std::string hash(const std::string& password);

    /**
     * Verify a plain-text password against a stored salted hash.
     * @param password      Plain-text password to verify
     * @param storedHash    Previously generated hash (format: "SALT$HASH")
     * @return              true if the password matches, false otherwise
     */
    static bool verify(const std::string& password, const std::string& storedHash);

    /**
     * Hash a password with a specific salt (useful for verification).
     * @param password  Plain-text password to hash
     * @param salt      Hex-encoded salt string
     * @return          Hex-encoded SHA-256 hash
     */
    static std::string hashWithSalt(const std::string& password, const std::string& salt);

private:
    static std::string generateSalt(size_t length = 16);
    static std::string sha256(const std::string& input);
    static std::string toHex(const uint8_t* data, size_t length);

    // SHA-256 internals
    static void sha256Transform(uint32_t state[8], const uint8_t block[64]);
    static const uint32_t K[64];
};