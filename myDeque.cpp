#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "myDeque.hpp"

// default constructor (nothing to do here)
template <typename T>
MyDeque<T>::MyDeque() {}

// construct a zero-initialized deque of size n
// uncomment the parameter name when 
// you implement this function
// (we commented it out to silence compiler warnings)
template <typename T>
MyDeque<T>::MyDeque(int n) {
  if (n % 2 == 0){
    frontVector = *new std::vector<T>(n/2);
    backVector = *new std::vector<T>(n/2);
  }
  else{
    frontVector = *new std::vector<T>(n/2 + 1);
    backVector = *new std::vector<T>(n/2);
  }
}

// Constructor from initializer list
// uncomment the parameter name when 
// you implement this function
// (we commented it out to silence compiler warnings)
template <typename T>
MyDeque<T>::MyDeque(std::initializer_list<T> vals) {
  if (vals.size() % 2 == 0){
    frontVector = *new std::vector<T>(vals.size()/2);
    backVector = *new std::vector<T>(vals.size()/2);
  }
  else{
    frontVector = *new std::vector<T>(vals.size()/2 + 1);
    backVector = *new std::vector<T>(vals.size()/2);
  }

  int i = 0; 
  int j = 0;
  for (T val : vals){
    if (((long unsigned int) i) < frontVector.size()){
      frontVector[i] = val;
      i++;
    }
    else{
      backVector[j] = val;
      j++;
    }
  }

  std::reverse(frontVector.begin(), frontVector.end());
}

// uncomment the parameter name when 
// you implement this function
// (we commented it out to silence compiler warnings)
template <typename T>
void MyDeque<T>::push_back(T val) {
  backVector.push_back(val);
}

// uncomment the parameter name when 
// you implement this function
// (we commented it out to silence compiler warnings)
template <typename T>
void MyDeque<T>::push_front(T val) {
  frontVector.push_back(val);
}

template <typename T>
void MyDeque<T>::pop_back() {
  if (backVector.empty()){
    rebalance_back();
  }

  backVector.pop_back();
}

template <typename T>
void MyDeque<T>::pop_front() {
  if (frontVector.empty()){
    rebalance_front();
  }

  frontVector.pop_back();
}

template <typename T>
T& MyDeque<T>::back() {
  // dummy line to prevent compiler warnings

  if (backVector.empty()){
    rebalance_back();
  }
  //dummy code, implement rebalance vector
  return backVector.back();

  for (T val : frontVector){
    std::cout << val << '\n';
  }
  for (T val : backVector){
    std::cout << val << '\n';
  }
}

template <typename T>
const T& MyDeque<T>::back() const {
  // dummy line to prevent compiler warnings

  return backVector.back();
}

template <typename T>
T& MyDeque<T>::front() {
  // dummy line to prevent compiler warnings
  if (frontVector.empty()){
    rebalance_front();
  }

  return frontVector.back();
}

template <typename T>
const T& MyDeque<T>::front() const {
  // dummy line to prevent compiler warnings

  return frontVector.back();
}

template <typename T>
bool MyDeque<T>::empty() const {
  return frontVector.size() + backVector.size() == 0;
}

template <typename T>
int MyDeque<T>::size() const {
  return frontVector.size() + backVector.size();
}

template <typename T>
T& MyDeque<T>::operator[](int i) {
  // dummy line to prevent compiler warnings
  unsigned long int j = (unsigned long int) i;
  return j < frontVector.size() ? frontVector[frontVector.size() - j - 1] : backVector[j - frontVector.size()];
}

template <typename T>
const T& MyDeque<T>::operator[](int i) const {
  // dummy line to prevent compiler warnings
  unsigned long int j = (unsigned long int) i;
  return j < frontVector.size() ? frontVector[frontVector.size() - j - 1] : backVector[j - frontVector.size()];
}

template <typename T>
void MyDeque<T>::rebalance_front(){
  //only call if front vector is empty

  std::vector<T> tempVectorFront;
  std::vector<T> tempVectorBack;

  if (backVector.size() % 2 == 0){
    tempVectorFront = *new std::vector<T>(backVector.size()/2);
    tempVectorBack = *new std::vector<T>(backVector.size()/2);
  }
  else {
    tempVectorFront = *new std::vector<T>(backVector.size()/2 + 1);
    tempVectorBack = *new std::vector<T>(backVector.size()/2);
  }
  
  int i = 0; 
  int j = 0;
  for (T val : backVector){
    if (((long unsigned int) i) < tempVectorFront.size()){
      tempVectorFront[i] = val;
      i++;
    }
    else{
      tempVectorBack[j] = val;
      j++;
    }
  }

  std::reverse(tempVectorFront.begin(), tempVectorFront.end());
  frontVector = tempVectorFront;
  backVector = tempVectorBack;
}

template <typename T>
void MyDeque<T>::rebalance_back(){
  //only call if back vector is empty

  std::vector<T> tempVectorFront;
  std::vector<T> tempVectorBack;

  if (frontVector.size() % 2 == 0){
    tempVectorFront = *new std::vector<T>(frontVector.size()/2);
    tempVectorBack = *new std::vector<T>(frontVector.size()/2);
  }
  else {
    tempVectorFront = *new std::vector<T>(frontVector.size()/2);
    tempVectorBack = *new std::vector<T>(frontVector.size()/2 + 1);
  }
  
  std::reverse(frontVector.begin(), frontVector.end());

  int i = 0; 
  int j = 0;
  for (T val : frontVector){
    if (((long unsigned int) i) < tempVectorFront.size()){
      tempVectorFront[i] = val;
      i++;
    }
    else{
      tempVectorBack[j] = val;
      j++;
    }
  }

  std::reverse(tempVectorFront.begin(), tempVectorFront.end());
  frontVector = tempVectorFront;
  backVector = tempVectorBack;
}

// Do not modify these lines.
// They are needed for the marker.
template class MyDeque<int>;
template class MyDeque<double>;
template class MyDeque<char>;
template class MyDeque<std::string>;
