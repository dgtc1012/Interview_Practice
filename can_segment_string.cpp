/*
String segmentation
    You are given a dictionary of words and a large input string. You have to find out whether the input string can be completely segmented into the words of a given dictionary.
Author: Dannah Gersh

TODO: implement memoization here to improve runtime - avoid repeating operation on second string for words already known by storing results of each word lookup - reduce runtime complexity from O(2^n) to O(n^2)
*/
#include <string>
#include <unordered_set>

bool can_segment_string(string s, unordered_set<string> &dictionary) {
    //loop through each letter in string
    for(int i = 0; i < s.length(); i++){
        //create substring from letter 0 to letter i
        string sub_str1 = s.substr(0, i);
        //if substring exists in the dictionary execute sub-code
        if(dictionary.find(sub_str1) != dictionary.end()){
            //create substring from letter i to end of string
            string sub_str2 = s.substr(i);
            /*check 3 criteria to see if string segments exist in dictionary:
                1. if second substring has anything in it, if not whole string was in dictionary, return true.
                2. if second substring is in dictionary, then str1 and str2 existed in dictionary, return true
                3. if substrings of string 2 existed in dictionary, whole string could be found - recursive call
               */
            if(sub_str2.empty() || dictionary.find(sub_str2) != dictionary.end() || can_segment_string(sub_str2, dictionary)){
                return true;
            }
        }
    }
  
  return false;
}