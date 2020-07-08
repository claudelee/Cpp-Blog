#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

using test_case  = std::function<void(void)>;
using test_suite = std::vector<test_case>;

template <typename T>
class point {
  T x, y, z, d;

  friend auto operator<<(std::ostream& os, const point& pt) -> std::ostream& {
    os << "(";
    os << pt.x << ", ";
    os << pt.y << ", ";
    os << pt.z << ", ";
    os << pt.d;
    os << ")";
    return os;
  }

public:
  explicit point(T x_, T y_, T z_, T d_) : x(x_), y(y_), z(z_), d(d_){};

  ~point() = default;
};

namespace beta {

template <class T>
class unique_ptr {
  T* m_ptr = nullptr;

public:
  explicit unique_ptr(T* ptr) : m_ptr(ptr) {
  }

  ~unique_ptr() {
    if (m_ptr) {
      delete m_ptr;
    }
    m_ptr = nullptr;
  }

  auto operator*() const -> T {
    return *m_ptr;
  }
};

} // namespace beta

auto test_raw_pointer(void) -> void {
  auto pt = new point<float>(1.2f, 2.3f, 3.4f, 4.5f);
  std::cout << *pt << std::endl;
  delete pt;
}

auto test_std_uniqure_ptr(void) -> void {
  auto pt = std::unique_ptr<point<float>>(new point<float>(1.2f, 2.3f, 3.4f, 4.5f));
  std::cout << *pt << std::endl;
}

auto test_beta_uniqure_ptr(void) -> void {
  auto pt = beta::unique_ptr<point<float>>(new point<float>(1.2f, 2.3f, 3.4f, 4.5f));
  std::cout << *pt << std::endl;
}

auto execute(test_suite xs) -> void {
  std::for_each(xs.begin(), xs.end(), [](test_case test_feature) { test_feature(); });
}

auto main(int, char*[]) -> int {
  execute(test_suite{test_raw_pointer, test_std_uniqure_ptr, test_beta_uniqure_ptr});
  return 0;
}
