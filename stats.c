/******************************************************************************
 * Copyright (C) 2020 by Saurav Sharma
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Saurav Sharma is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Header file for assignment C1M1 - stats
 *
 * Implements various functions for analysis of a given array
 *
 * @author Saurav Sharma
 * @date 23 Nov 2018
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  puts("ARRAY");
  print_array(test, SIZE);
  puts("\nSORTED ARRAY");
  print_array(sort_array(test, SIZE), SIZE);
  puts("\nSTATISTICS");
  print_statistics(test);
  /* Other Variable Declarations Go Here */
}

void print_statistics(unsigned char * data){
  printf("Median  = %.1f\n", find_median(data, SIZE));
  printf("Mean    = %.3f\n", find_mean(data, SIZE));
  printf("Maximum = %d\n", find_maximum(data, SIZE));
  printf("Minimum = %d\n", find_minimum(data, SIZE));
}

void print_array(unsigned char * data, unsigned int length){
  for(int i=0; i<length; i++){
    if(i == length-1){
      printf("%d\n", data[i]);
    }else{
      printf("%d,", data[i]);
    }
  }
}

float find_median(unsigned char * data, unsigned int length){
  data = sort_array(data, length);
  float median;
  if(SIZE % 2 == 0){
    median = (data[length/2] + data[(length/2)-1])/2.0;
  }else{
    median = data[length/2];
  }
  return median;
}
  
float find_mean(unsigned char * data, unsigned int length){
  float sum = 0.0;
  for(int i=0; i<length; i++){
    sum += data[i];
  }
  return sum/length;
}

unsigned int find_maximum(unsigned char * data, unsigned int length){
  unsigned int maximum = 0;
  for(int i=0; i<length; i++){
    if(data[i] > maximum){
      maximum = data[i];
    }
  }
  return maximum;
}
  
unsigned int find_minimum(unsigned char * data, unsigned int length){
  unsigned int minimum = data[0];
  for(int i=1; i<length; i++){
    if(data[i] < minimum){
      minimum = data[i];
    }
  }
  return minimum;
}

unsigned char* sort_array(unsigned char * data, unsigned int length){
  for(int i=length-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(data[j]>data[j+1]){
        unsigned char temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }  
  return data;
}


