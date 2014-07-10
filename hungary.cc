#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::iterator iter;

void hungary(vector<int>& arr)
{

  iter left = arr.begin();
  iter right = arr.end() - 1;
  


}



int main() {
  int x[] = {1, 0, 2};
  vector<int> arr(x, x + 3);
  hungary(arr);

  for (iter i = arr.begin(); i != arr.end(); i++) {
    cout << *i <<endl;
  }
  return 0;
}
