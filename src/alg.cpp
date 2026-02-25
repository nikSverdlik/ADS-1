// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (uint64_t i = 2; i <= value; i++) {
      if (value%i == 0 && i != value) {
          return false;
      }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t numOfPrime = 0;
  uint64_t chekChislo = 1;
  if (n < 1) return 0;
  while (numOfPrime < n) {
      chekChislo++;
      if (checkPrime(chekChislo)) {
          numOfPrime++;
      }
  }
  return chekChislo;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t nextChislo = value + 1;
  while (!checkPrime(nextChislo)) {
      nextChislo++;
  }
  return nextChislo;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t primeSum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
      if (checkPrime(i)) {
          primeSum += i;
      }
  }
  return primeSum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t couples = 0;
  for (uint64_t i = lbound; i + 2 < hbound; i++) {
      if (checkPrime(i) && checkPrime(i + 2)) {
          couples++;
      }
  }
  return couples;
}
