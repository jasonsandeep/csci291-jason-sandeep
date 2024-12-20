// Libraries in use
#include <stdio.h>
#include <stdbool.h> 

// Setting values for SIZE, nRows, nCols
#define SIZE 24
#define nRows 8
#define nCols 3

// PROTOTYPES
void print_array(int array[], int length); //pre-declared function for printing array
void print_matrix(int mat[][nCols], int rows); //pre-declared function for printing matrix

void set_array(int arr[], int length); //prototype for function for setting array
bool isValid(int arr[], int length, int pos); // prototype for function for checking if indices are valid
void remove_element(int arr[], int length, int pos); //prototype for function for removing an element from array
void insert_element(int arr[], int length, int pos, int value); //prototype for function for inserting element into array
void reshape(int arr[], int length, int arr2d[nRows][nCols]); //prototype for function for copying elements from array to array2d
void trans_matrix(int arr2d[nRows][nCols]); //prototype for function for printing columns of matrix
bool found_duplicate(int arr[], int length); //prototype for function that checks for duplicates in array

// initialising code - FUNCTION CALLS
int main()
{
   int arr[SIZE]; //initialising array 'arr' having pre-defined SIZE
   int arr2d[nRows][nCols]; //initialising array 'arr2d' having pre-defined rows & columns
     
   //Call to different functions

   //Setting value of element to index
   set_array(arr, SIZE); //calling the function that sets the array

   //Printing initial array
   printf("Array in the start: \n");
   print_array(arr,SIZE); //calling the function that prints the array

   //Removing one element
   int remove = 5; 
   remove_element (arr, SIZE, remove); 
    puts("");
   printf("Array after removing element at position %d: \n", remove);
   print_array(arr, SIZE-1);

   // Inserting an element
   int new_element = 25;
   int insert = 5; 
   insert_element(arr, SIZE-1, insert, new_element); 
   puts("");
   printf("Array after inserting %d at position %d: \n", new_element,insert);
   print_array(arr, SIZE); 
   
   reshape(arr, SIZE, arr2d); //calling the function that reshaps arr to arr2d
   puts("");
   printf("Array2D after reshaping: \n");
   print_matrix(arr2d, nRows);
   
   printf("Column-wise print of arr2d: \n");
   trans_matrix(arr2d); //printing matrix columns of arr2d

   //Searching for duplicates in arr
   found_duplicate(arr,SIZE);

   return 0;
}

// printing the array
void print_array(int array[], int length){
   for(int i=0;i<length; i++)
      printf("array[%d]= %d\n", i, array[i]);
}

// printing the matrix (rows)
void print_matrix(int mat[][nCols], int rows){
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

//FUNCTION DEFINITIONS

//making an array
void set_array(int arr[], int length) {
   for (int i = 0; i<length; i++){
      arr[i] = i; 
   }
}

//isValid()
bool isValid(int arr[],int length, int pos) {
    if (pos >= 0 && pos < length) {
        return true;
        
    }
    else {
        return false;
    }
}

//remove_element()
void remove_element(int arr[], int length, int pos) {
   if (isValid(arr,length,pos)) {
        for (int i = pos; i < length - 1; i++) { 
            arr[i] = arr[i + 1]; 
      }
   }
   else {
      printf("Incorrect array index entered.\n"); 
   }
}

//insert_element()
void insert_element(int arr[], int length, int pos, int value) {
   if (isValid(arr,length,pos)) { 
      for (int i = length; i > pos; i--) {
         arr[i] = arr[i - 1]; 
      }
      arr[pos] = value;
   } else {
      printf("Incorrect array index entered. \n");
   }
}

//reshape()
void reshape(int arr[], int length, int arr2d[nRows][nCols]) {
   if (length == (nRows*nCols)){ 
      int position = 0;
      for (int i = 0; i< nRows; i++) {
         for (int j = 0; j< nCols; j++) {
            if (position < length) {
               arr2d[i][j] = arr[position]; 
               position++;
            }
         }
      }
   } else{
      printf("Array length does not match the product of rows & columns of the 2D array.\n"); 
   }
}

void trans_matrix(int arr2d[nRows][nCols]) {
   for (int j = 0; j < nCols; j++) {
      for (int i = 0; i < nRows; i++) { // nested loop
         printf("%d ", arr2d[i][j]);
      }
      printf("\n");
   }
}

//searching for duplicates
bool found_duplicate(int arr[], int length) {
   for (int i = 0; i < length; i++) {
      for (int j = i+1; j< length; j++){ //nested loop
         if (arr[i] == arr[j]) {
            printf("Duplicates found in array. \n"); // if duplicates found
            return true;
         }
      }
   }
   printf("No duplicates found. \n"); // if duplicates not found
   return false;
}



