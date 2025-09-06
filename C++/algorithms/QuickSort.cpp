//? Link    -> https://www.techiedelight.com/quicksort/
//? Gif     -> https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.tutorialspoint.com%2Fdata_structures_algorithms%2Fquick_sort_algorithm.htm&psig=AOvVaw1AMTsFUdySjdTfDwVWNtLO&ust=1698315297112000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCJD8kdL7kIIDFQAAAAAdAAAAABAE

#include <iostream>

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

int partition(int nums[], const int &start, const int &end) {
    // Pick the rightmost element as a pivot from the array
    int pivot = nums[end];

    // elements less than the pivot will be pushed to the left of `p_index`
    // elements more than the pivot will be pushed to the right of `p_index`
    int p_index = start;

    for (int i=start; i<end; ++i) {
        if (nums[i] < pivot) {
            swap(nums[i], nums[p_index]);
            p_index++;
        } 
    }

    swap(nums[p_index], nums[end]);

    return p_index;
}

void quicksort(int nums[], int start, int end) {
    // base condition
    if (start >= end) return;

    // get the pivot index
    int pivot = partition(nums, start, end);

    // quicksort on the subarray containing elements that are less than the pivot
    quicksort(nums, start, pivot-1);

    // quicksort on the subarray containing elements that are more than the pivot
    quicksort(nums, pivot+1, end);
}

int main () {
    int nums[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int n = sizeof(nums)/sizeof(nums[0]);

    // quicksort
    quicksort(nums, 0, n-1);
    
    // print the array
    for (int i=0; i<n; ++i) {
        printf("%d ", nums[i]);
    }

    return 0;
}