#include <functional>
#include <iostream>
#include <vector>

using test_case  = std::function<void(void)>;
using test_suite = std::vector<test_case>;

auto log(const char* const signature) -> void {
  std::cout << "[log] " << signature << std::endl;
}

auto show_exp(int augend, int addend, int sum) -> void {
  std::cout << "sum(" << augend << ", " << addend << ") = " << sum << std::endl;
}

auto test_subroutine(void) -> void {
  log(__PRETTY_FUNCTION__);

  auto augend = int(3);
  auto addend = int(4);
  auto sum    = [](int augend, int addend) -> int { return augend + addend; };
  show_exp(augend, addend, sum(augend, addend));
}

auto test_capture_by_value(void) -> void {
  log(__PRETTY_FUNCTION__);

  auto augend = int(3);
  auto addend = int(4);
  auto sum    = [factor = 1](int augend, int addend) -> int { return (augend + addend) << factor; };
  show_exp(augend, addend, sum(augend, addend));
}

auto test_capture_by_reference(void) -> void {
  log(__PRETTY_FUNCTION__);

  auto augend = int(3);
  auto addend = int(4);
  auto factor = int(1);
  auto sum    = [&](int augend, int addend) -> int { return (augend + addend) << factor; };
  show_exp(augend, addend, sum(augend, addend));
}

auto execute(test_suite xs) -> void {
  std::for_each(xs.begin(), xs.end(), [](test_case test_feature) {
    test_feature();
    std::cout << std::endl;
  });
}

auto main(int, char*[]) -> int {
  execute(test_suite{test_subroutine, test_capture_by_value, test_capture_by_reference});
  return 0;
}
