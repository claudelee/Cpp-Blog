#include <stdint.h>

// clang-format off
auto little_to_big(int32_t num) -> int32_t {
  return (num >> 24 & 0x000000FF) ^ 
         (num >> 8  & 0x0000FF00) ^ 
         (num << 8  & 0x00FF0000) ^ 
         (num << 24 & 0xFF000000);
}
// clang-format on

auto main(int, char*[]) -> int {
  auto m = int32_t(0x12345678);
  auto n = little_to_big(m);
  return 0;
}
