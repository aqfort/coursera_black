#include <iostream>

using namespace std;

// Little Endian

int main()
{
  uint32_t value = 0xABCDEF01;
  uint32_t *p = &value;

  uint8_t *p1 = reinterpret_cast<uint8_t *>(p); // 0x01
  uint8_t *p2 = p1 + 1;                         // 0xef
  uint8_t *p3 = p2 + 1;                         // 0xcd
  uint8_t *p4 = p3 + 1;                         // 0xab

  int64_t val = 0x0123456789abcdef;
  int64_t *p64 = &val;                             // 0x0123456789abcdef
  int32_t *p32 = reinterpret_cast<int32_t *>(p64); // 0x89abcdef
  int16_t *p16 = reinterpret_cast<int16_t *>(p64); // 0xcdef
  int8_t *p8 = reinterpret_cast<int8_t *>(p64);    // 0xef

  return 0;
}
