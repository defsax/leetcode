#include <iostream>
#include <vector>
#include <map>
#include <chrono>

  //loop over array once
  //keep track of numbers already checked
  //if current number plus an already checked number equals target, return (map index/ current index)
  //otherwise add it to map 

std::vector<int> twoSumMap(std::vector<int>& nums, const int& target){
  std::map<int, int> prevNums;
  std::map<int, int>::iterator it = prevNums.begin();
  bool numFound = false;
  
  //loop over array once
  for(unsigned int i = 0; i < nums.size(); i++){
    
    //first element/nothing to check against
    if(i == 0){
      prevNums.insert(std::pair<int, int>(i, nums.at(i)));
      continue;
    }
    
    //reset iterator to beginning of map
    it = prevNums.begin();
    
    while(it != prevNums.end()){
      if(nums.at(i) + it->second == target){
        std::vector<int> answer;
        answer.push_back(i);
        answer.push_back(it->first);
        return answer;
      }
      it++;
    }
    
    //if, after checking previousnums map nothing is found, add current num to prevnums
    if(!numFound){
      prevNums.insert(std::pair<int, int>(i, nums.at(i)));
    }
  }
  
  for(const auto &pair : prevNums)
    std::cout << pair.first << ": " << pair.second << std::endl;
  
  std::cout << "No solution found." <<  std::endl;
  std::vector<int> nothing;
  return nothing;
}


std::vector<int> twoSum(std::vector<int>& nums, const int& target){
  
  for(unsigned int i = 0; i < nums.size(); i++){
    std::cout << nums.at(i) << std::endl;
    
    int addition = nums.at(i);
    
    for(unsigned int j = 0; j < nums.size(); j++){
      if(nums.at(i) != nums.at(j)){
        addition = nums.at(i) + nums.at(j);
        std::cout << "Added " << nums.at(i) << " + " << nums.at(j) << ": " << addition << std::endl;
        
        if(addition == target){
          std::cout << "Found solution." << std::endl;
          std::vector<int> result;
          result.push_back(i);
          result.push_back(j);
          
          return result;
        }
      }
      else{
        std::cout << "Skipping. Same element." << std::endl;
        continue;
      }
    }
    std::cout << std::endl;
  }
  std::cout << "No solution found." <<  std::endl;
  std::vector<int> nothing;
  return nothing;
}

int main(){
  
  int nums1[] = {2, 7, 11, 15}; 
  int target = 9;
  std::vector<int> a(nums1, nums1 + sizeof(nums1) / sizeof(int));
  
  auto t1 = std::chrono::high_resolution_clock::now();
  twoSum(a, target);
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Two sum using brute force function took " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << " microseconds\n" << std::endl;
  
  
  t1 = std::chrono::high_resolution_clock::now();
  twoSumMap(a, target);
  t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Two sum using map function took " << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() << " microseconds\n" << std::endl;
  
//   //print out elements of nums array
//   for(int i = 0; i < sizeof(nums1) / sizeof(int); i++)
//     std::cout << nums1[i] << std::endl;
//   
//   //print out elements of nums vector
//   for(int i = 0; i < a.size(); i++)
//     std::cout << a.at(i) << ' ';
  
  int nums2[] = {3, 2, 4};
  target = 6;
  std::vector<int> b(nums2, nums2 + sizeof(nums2) / sizeof(int));
//   twoSum(a, target);
  twoSumMap(b, target);
  
  int nums3[] = {3, 3};
  target = 6;
  std::vector<int> c(nums3, nums3 + sizeof(nums3) / sizeof(int));
//   twoSum(a, target);
  twoSumMap(c, target);
  
  
  int nums4[] = {3, 3, 8, 19, 2, 7, 1, 4};
  target = 23;
  std::vector<int> d(nums4, nums4 + sizeof(nums4) / sizeof(int));
//   twoSum(a, target);
  twoSumMap(d, target);
  
  std::cout << "Program run." << std::endl;
  return 0;
}

