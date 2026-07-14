# merge-sort-performance-analysis
Developed a C++ project implementing the traditional Merge Sort algorithm alongside an optimized Merge Sort V2. The project evaluates algorithm performance by measuring execution times on various dataset arrangements, demonstrating the impact of optimization techniques on sorting efficiency.
# Merge Sort Performance Analysis (V1 vs V2)

## Overview

This project compares the performance of the traditional Merge Sort algorithm (V1) with an enhanced implementation (Merge Sort V2) developed to improve efficiency on partially or fully sorted datasets.

Both implementations are written in **C++** and benchmarked using the `<ctime>` library to measure execution time while sorting datasets containing up to **100,000 integers**.

---

## Merge Sort Versions

### Merge Sort V1
The traditional recursive Merge Sort algorithm follows the standard divide-and-conquer approach:

- Recursively splits the array into two halves.
- Sorts each half independently.
- Merges the two sorted halves.
- Time Complexity:
  - Best Case: **O(n log n)**
  - Average Case: **O(n log n)**
  - Worst Case: **O(n log n)**

---

### Merge Sort V2 (Enhanced)

Merge Sort V2 introduces two implementation improvements while preserving the original algorithm:

### ✔ Early Exit Optimization

Before performing the merge operation, V2 checks whether the two sorted halves are already in order.

```cpp
if (theArray[mid] <= theArray[mid + 1])
    return;
```

If this condition is true, the merge step is skipped entirely since both subarrays are already correctly ordered.

This optimization significantly improves performance on already sorted or nearly sorted data.

---

### ✔ Reusable Global Temporary Array

Instead of creating a temporary array inside every merge call, Merge Sort V2 allocates a single global temporary array that is reused throughout the recursion.

Benefits include:

- Reduces repeated memory allocation
- Lowers recursion overhead
- Improves cache efficiency
- Produces cleaner and faster merge operations

---

## Performance Benefits

Merge Sort V2 performs identically to the traditional version on random datasets while providing noticeable improvements on sorted input.

| Dataset | Merge Sort V1 | Merge Sort V2 |
|----------|---------------|---------------|
| Random | ~0.017 s | ~0.017 s |
| Sorted (Ascending) | ~0.010 s | ~0.0013 s |
| Sorted (Descending) | ~0.009 s | ~0.011 s |

The early-exit optimization provides approximately a **7.5× speed improvement** on ascending datasets by eliminating unnecessary merge operations.

---

## Time Complexity

| Case | Merge Sort V1 | Merge Sort V2 |
|------|---------------|---------------|
| Best | O(n log n) | O(n)* |
| Average | O(n log n) | O(n log n) |
| Worst | O(n log n) | O(n log n) |

\*Best-case performance approaches **O(n)** when merge operations are consistently skipped because adjacent subarrays are already ordered.

---

## Technologies Used

- C++
- `<fstream>`
- `<ctime>`
- Recursive Divide-and-Conquer Algorithm

---

## How to Run

1. Clone this repository.

```bash
git clone https://github.com/yourusername/merge-sort-v2.git
```

2. Open the project in Visual Studio or any C++ IDE.

3. Compile and run either:

- `Mergesort V1.cpp`
- `Mergesort V2.cpp`

4. Provide the input dataset and compare execution times.

---

## Project Goal

The objective of this project is to evaluate how a small algorithmic enhancement can improve the practical performance of Merge Sort while maintaining its theoretical efficiency.

By eliminating unnecessary merge operations and reducing memory overhead, Merge Sort V2 demonstrates that implementation-level optimizations can produce measurable real-world performance gains without changing the algorithm's core design.

---

## Author

**Aamir Mohammed**

Bachelor of Science in Artificial Intelligence  
American University of Ras Al Khaimah
