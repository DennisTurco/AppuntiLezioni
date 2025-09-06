//? Link    -> https://www.techiedelight.com/bubble-sort-iterative-recursive/
//? Gif     -> https://www.google.com/url?sa=i&url=https%3A%2F%2Fcommons.wikimedia.org%2Fwiki%2FFile%3ABubble-sort-example-300px.gif&psig=AOvVaw2aD9Cb5C7gCOUq3fL1DjQK&ust=1698317908046000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCJCska-FkYIDFQAAAAAdAAAAABAj

#include <iostream>

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void printarray(const int nums[], const int &n) {
    for (int i=0; i<n; ++i) {
        printf("%d ", nums[i]);
    }
}

void bubblesort(int nums[], const int &n) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-1-i; ++j) {
            if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]); 
        }
    }
}

int main () {
    int nums[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int n = sizeof(nums)/sizeof(nums[0]);

    bubblesort(nums, n);

    printarray(nums, n);

    return 0;
}