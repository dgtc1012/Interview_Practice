/*
    Determine if the sum of two integers is equal to the given value
        Given an array of integers and a value, determine if there are any two integers in the array whose sum is equal to the given value. Return true if the sum exists and return false if it does not.
*/
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <unordered_set>

bool find_sum_of_two(const std::vector<int> *A, int val){
    std::unordered_set<int> options;
    
    for(int i = 0; i < A->size(); i++)
    {
        if(options.find(val - A->at(i)) != options.end()){
            return true;
        }
        options.insert(A->at(i));
    }
    return false;
}

int main() {
  std::vector<int> v = {5, 7, 1, 2, 8, 4, 3};
  std::vector<int> test = {3, 20, 1, 2, 7};

  for(int i=0; i<test.size(); i++){
    bool output = find_sum_of_two(&v, test[i]);
    std::cout << "find_sum_of_two(v, " << test[i] << ") = " << (output ? "true" : "false") << std::endl;
  }
  return 0;
}