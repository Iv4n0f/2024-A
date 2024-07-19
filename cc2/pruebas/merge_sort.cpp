#include <future>
#include <iostream>
#include <vector>

using namespace std;
void merge(int low, int mid, int high, vector<int> &num) {
  vector<int> copy(num.size());
  int h, i, j, k;
  h = low;
  i = low;
  j = mid + 1;
  while ((h <= mid) && (j <= high)) {
    if (num[h] <= num[j]) {
      copy[i] = num[h];
      h++;
    } else {
      copy[i] = num[j];
      j++;
    }
    i++;
  }
  if (h > mid) {
    for (k = j; k <= high; k++) {
      copy[i] = num[k];
      i++;
    }
  } else {
    for (k = h; k <= mid; k++) {
      copy[i] = num[k];
      i++;
    }
  }
  for (k = low; k <= high; k++)
    swap(num[k], copy[k]);
}

void merge_sort(int low, int high, vector<int> &num) {
  int mid;
  if (low < high) {
    mid = low + (high - low) / 2;
    auto future1 =
        std::async(std::launch::deferred, [&]() { merge_sort(low, mid, num); });
    auto future2 = std::async(std::launch::deferred,
                              [&]() { merge_sort(mid + 1, high, num); });
    future1.get();
    future2.get();
    merge(low, mid, high, num);
  }
}


void print(vector<int>&nums){
  for(auto num : nums){
    cout<<num<<" ";
  }
}

int main(){
  vector<int> num;

  srand(time(NULL));
  for(int i = 0; i<1000;i++){
    num.push_back(rand()%1000);
  }

  merge_sort(0, 999, num);
  print(num);
}
