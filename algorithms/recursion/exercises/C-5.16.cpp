#include <array>
#include <iostream>
#include <vector>

void print_platform(std::array<std::vector<int>, 3> platform) {
  for (std::vector<int> pale : platform) {
    std::cout << '|';
    for (int disk : pale) {
      std::cout << disk;
    }
    std::cout << std::endl;
  }
}

void move_disk(std::array<std::vector<int>, 3> &platform, int from, int to) {
  platform[to].push_back(platform[from][platform[from].size() - 1]);
  platform[from].pop_back();
}

void solve_hanoi(std::array<std::vector<int>, 3> &platform, int from, int to,
                 int temp, int count) {
  if (count == 1) {
    move_disk(platform, from, to);
    return;
  }

  // Move n-1 disks from pale 'from' to pale 'temp'
  solve_hanoi(platform, from, temp, to, count - 1);
  // Move the base disk from pale 'from' to pale 'to'
  move_disk(platform, from, to);
  // Move back n-1 disks from pale 'temp' to pale 'to'
  solve_hanoi(platform, temp, to, from, count - 1);
}

int main() {
  std::array<std::vector<int>, 3> platform;

  for (int i = 8; i > 0; i--) {
    platform[0].push_back(i);
  }

  print_platform(platform);
  solve_hanoi(platform, 0, 1, 2, platform[0].size());
  std::cout << "----------------------------------\n";
  print_platform(platform);

  return 0;
}