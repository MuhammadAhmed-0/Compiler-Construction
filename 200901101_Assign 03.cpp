#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

const int N = 1e5;  // size of the array to sort
int a[N];  // array to sort

// merge function to merge two sorted subarrays
void merge(int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // create temporary arrays
  int L[n1], R[n2];

  // copy data to temporary arrays
  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

  // merge the temporary arrays back into a[l..r]
  i = 0;  // initial index of first subarray
  j = 0;  // initial index of second subarray
  k = l;  // initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }

  // copy the remaining elements of L[], if there are any
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  // copy the remaining elements of R[], if there are any
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

// function to sort an array using merge sort
void merge_sort(int l, int r) {
  if (l < r) {
    // find the middle point
    int m = l + (r - l) / 2;

    // sort the first and second halves
    merge_sort(l, m);
    merge_sort(m + 1, r);

    // merge the sorted halves
    merge(l, m, r);
  }
}

int main() {
  int n;  // number of elements in the array

  // get the number of elements in the array from the user
  cout << "Enter the number of elements: ";
  cin >> n;

  // get the elements of the array from the user
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // sort the array using multithreaded merge sort
  int cores = thread::hardware_concurrency();
  thread t1(merge_sort, 0, n / 2 - 1);
  thread t2(merge_sort, n / 2, n - 1);
  t1.join();
  t2.join();

  // merge the sorted halves
  merge(0, n / 2 - 1, n - 1);
// print the sorted

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
  cout << a[i] << " ";
  cout << endl;

  return 0;
}
  