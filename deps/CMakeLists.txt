set(wolfssl_src
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/crl.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/internal.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/keys.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/ocsp.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/sniffer.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/ssl.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/tls.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/tls13.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/src/wolfio.c)
set(wolfcrypt_src
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/aes.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/cmac.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/des3.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/dh.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/ecc.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/hmac.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/random.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/rsa.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sha.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sha256.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sha512.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sha3.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/asn.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/chacha.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/cmac.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/coding.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/compress.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/cpuid.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/cryptocb.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/curve25519.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/ed25519.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/error.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/fe_low_mem.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/fe_operations.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/ge_low_mem.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/ge_operations.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/hash.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/integer.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/logging.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/md5.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/memory.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/pkcs12.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/pkcs7.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/poly1305.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/pwdbased.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/signature.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/srp.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sp_arm32.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sp_arm64.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sp_c32.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/sp_int.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/tfm.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/wc_encrypt.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/wc_port.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/wolfevent.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/wolfmath.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/arc4.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/blake2b.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/camellia.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/dsa.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/hc128.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/idea.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/md2.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/md4.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/rabbit.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl/wolfcrypt/src/ripemd.c)

add_library(wolfssl ${wolfssl_src} ${wolfcrypt_src})
target_compile_definitions(wolfssl PRIVATE WOLFSSL_USER_SETTINGS)
target_include_directories(wolfssl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/wolfssl
    ${CMAKE_CURRENT_LIST_DIR}/wolfssl_init)

set(wolfmqtt_src
    ${CMAKE_CURRENT_LIST_DIR}/wolfmqtt/src/mqtt_client.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfmqtt/src/mqtt_packet.c
    ${CMAKE_CURRENT_LIST_DIR}/wolfmqtt/src/mqtt_socket.c)
add_library(wolfmqtt ${wolfmqtt_src})
target_compile_definitions(wolfmqtt PRIVATE WOLFMQTT_USER_SETTINGS)
target_include_directories(wolfmqtt PUBLIC ${CMAKE_CURRENT_LIST_DIR}/wolfmqtt)
