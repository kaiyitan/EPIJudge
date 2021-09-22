#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  int result = 0; 
  while(x){
    if(x&1) result ^=1;
    x >>= 1;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
