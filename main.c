#include <stdio.h>


int quadratic_s(int x, int a, int b, int c);
int sum_array_s(int *array, int n);
int find_max_s(int *array, int n);
int fib_iter_s(int n);
int fib_rec_s(int n);
int strlen_s(char* s);


int quadratic_c(int x, int a, int b, int c)
{
    int result = (a * (x * x)) + (b * x) + c;
    return result;
}

int sum_array_c(int *array, int n)
{
    int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum = sum + array[i]; 
    }

    return sum;
}



int fib_iter_c(int n) {
    int prev_prev_num = 0, prev_num = 0, cur_num = 1;

    if (n == 0) {
        return 0;
    }
    for (int i = 1; i < n ; i++) {
        prev_prev_num = prev_num;
        prev_num = cur_num;
        cur_num = prev_prev_num + prev_num;
    }
    return cur_num;
}

int fib_rec_c(int n)
{
    if (n <= 2) {
        return 1;
    } else {
        return fib_rec_c(n - 2) + fib_rec_c(n - 1);
    }
}

int find_max_c(int *array, int n)
{
    int i;
    int max = array[0];

    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max; 
}

int strlen_c(char *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;
}

int main(void) {
	
    int small[] = {8, 5, 3, 11, 6};
    char length[] = "drastically";
    int arr[10]; 
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }


   printf("Quadratic Test, Input: 5, 3, 4, 2\nC:%u\nARM:%u\n\n",quadratic_c(5, 3, 4, 2), quadratic_s(5, 3, 4, 2));
   printf("Array Sum Test Input: [1 - 10]\nC:%u\nARM:%u\n\n", sum_array_c(arr, 10), sum_array_s(arr, 10));
    printf("Find Max Test Input: [2, 5, 3, 11, 6] \nC:%u\nARM:%u\n\n",find_max_c(small, 5) ,find_max_s(small, 5));
    printf("Fibonacci Iterative Input: 20\nC:%u\nARM:%u\n\n", fib_iter_c(20), fib_iter_s(20));
    printf("Fibonacci Recursuive Input: 20\nC:%u\nARM:\n\n",fib_rec_c(20));  
  printf("String Length Test Input: %s\nC:%u\nARM:%u\n",length, strlen_c(length), strlen_s(length));
}
