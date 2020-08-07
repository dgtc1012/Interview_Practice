/*
    This program will implement a solution to the problem "find the missing number in the array"
        You are given an array of positive numbers from 1 to n, such that all numbers from 1 to n are present except one number x. You have to find x. The input array is not sorted.
    Author: Dannah Gersh
*/
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib> 
#include <algorithm>

int missing_num(std::vector<int> const *input){
    int answer = -1;
    int expected_sum = 0;
    int actual_sum = 0;
    
    for(int i = 0; i < input->size() + 1; i++){
        expected_sum += (i+1);
    }
    printf("Expected sum: %d\n", expected_sum);
    
    for(int i = 0; i < input->size(); i++){
        actual_sum += input->at(i);
    }
    printf("Actual sum: %d\n", actual_sum);
    
    answer = expected_sum - actual_sum;
    
    return answer;
}

int main(){
    int n = 10;
    std::cout << "Enter size of array greater than or equal to 4: ";
    std::cin >> n;
    
    if(n < 4){
        n = 10;
    }
    
    printf("Array size: %d\n", n);
    
    std::vector<int> arr;
    int missing = rand() % n + 1;
    printf("Missing num will be: %d\n", missing);
    
    for(int i = 1; i < n; i++)
    {
        if(i != missing)
        {
            arr.push_back(i);
        }
    }
    std::random_shuffle(arr.begin(), arr.end());
    printf("\n");
    for(int i=0; i<arr.size(); ++i)
        std::cout << arr[i] << ' ';
    printf("\n");
    int answer = missing_num(&arr);
    printf("answer is: %d\n", answer);
}