#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <vector>

std::mutex mtx;

template <typename T>
class point {
  friend auto operator<<(std::ostream& os, const point& pt) -> std::ostream& {
    os << "(x, y, z) = (" << pt.x << ", " << pt.y << ", " << pt.z << ")";
    return os;
  }

  T x;
  T y;
  T z;

public:
  explicit point(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {
  }

  ~point() = default;
};

auto spawn(void) -> std::vector<std::thread> {
  auto workers = std::vector<std::thread>();
  auto rnd_eng = std::random_device();
  auto gen     = std::mt19937(rnd_eng());
  auto dist    = std::uniform_real_distribution<>(1.0, 10.0);
  for (auto idx = 1; idx <= 10; ++idx) {
    auto x  = static_cast<float>(dist(gen));
    auto y  = static_cast<float>(dist(gen));
    auto z  = static_cast<float>(dist(gen));
    auto pt = point(x, y, z);
    workers.emplace_back(
        [](const point<float>& pt) {
          mtx.lock();
          std::cout << pt << std::endl;
          mtx.unlock();
        },
        std::cref(pt));
  }
  return workers;
}

auto main(int, char*[]) -> int {
  auto workers = spawn();
  for (auto& worker : workers) {
    worker.join();
  }
  return 0;
}
