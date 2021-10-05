Collection of some sorting algorithms implementation in C++, including efficient ones.

# Algorithms and Efficiency comparison

### Bubble sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n) | O(n^2) | O(n^2) |
| Space complexity | O(1) | O(1) | O(1) |

### Selection sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n^2) | O(n^2) | O(n^2) |
| Space complexity | O(1) | O(1) | O(1) |

### Insertion sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n) | O(n^2) | O(n^2) |
| Space complexity | O(1) | O(1) | O(1) |

### Merge sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n log n) | O(n log n) | O(n log n) |
| Space complexity | O(n) | O(n) | O(n) |

### Heap sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n log n) | O(n log n) | O(n log n) |
| Space complexity | O(1) | O(1) | O(1) |

### Quick sort
| | Best-case | Average | Worst-case |
|-|:-:|:-:|:-:|
| Performance | O(n log n) | O(n log n) | O(n^2) |
| Space complexity | O(1) | O(1) | O(1) |

# Benchmark
Time spended to sort `std::vector<int>` array with randomly generated values in range [-10000, 10000].

| Size | 10.000 | 100.000 | 1.000.000 | 10.000.000 | 100.000.000 |
|:-:|:-:|:-:|:-:|:-:|:-:|
| Merge sort | 0 ms | 9 ms | 113 ms | 1218 ms | 12 s
| Heap sort | 0 ms | 8 ms | 151 ms | 3355 ms | 55 s
| Quick sort | 0 ms | 7 ms | 71 ms | 710 ms | 7 s