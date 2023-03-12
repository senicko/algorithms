#include <iostream>

bool rec_binary_search(int data[], int target, int low, int high) {
  if (low > high)
    return false;

  int mid = low + (high - low) / 2;

  if (target == data[mid]) {
    return true;
  } else if (target < data[mid]) {
    return rec_binary_search(data, target, low, mid - 1);
  } else {
    return rec_binary_search(data, target, mid + 1, high);
  }
}

// recursive binary search implementation is an example of tail recursion.
// It means that we can implement it iteratively by using a loop for repetition
// and by creating variables for our state.
bool iter_binary_search(int data[], int target, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (data[mid] == target) {
      return true;
    } else if (target < data[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return false;
}

int main() {
  int data[7] = {1, 45, 6789, 123415, 68549759, 92982462, 999999999};
  int target = data[3];

  bool is_present_rec = rec_binary_search(data, target, 0, 6);
  bool is_present_iter = iter_binary_search(data, target, 0, 6);
  std::cout << is_present_iter << ' ' << is_present_rec;

  return 0;
}