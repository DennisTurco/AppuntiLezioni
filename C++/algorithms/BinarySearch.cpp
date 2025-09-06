//? Link    -> https://www.techiedelight.com/binary-search/
//? Gif     -> https://www.google.com/url?sa=i&url=https%3A%2F%2Fbrilliant.org%2Fwiki%2Fbinary-search%2F&psig=AOvVaw1267PnSRKlxdrHHJCcb57O&ust=1698312635097000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCMCV6tzxkIIDFQAAAAAdAAAAABAL

#include <iostream>

// iterative method
int binary_search(const int nums[], const int &target, const int &n) {
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (high+low) / 2;

        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

// recursive method
int binary_search_recursive(const int nums[], const int &target, const int &low, const int &high) {
    // base case
    if (low > high) return -1;

    int mid = (high+low) / 2;

    // base condition
    if (target == nums[mid]) return mid;
    
    // recursive call
    else if (target < nums[mid]) binary_search_recursive(nums, target, low, mid-1);
    
    // recursive call
    else binary_search_recursive(nums, target, low+1, high);
}

int main () {
    int nums[] = { 2, 5, 6, 8, 9, 10 }; // the array must be sorted
    int target = 8;

    // get the dim of the array:
    // 1. sizeof(nums) -> gets the dim (in bytes) of the whole array. ex: if the array contains 5 numbers, sizeof(nums) = 5*4 = 20
    // 2. sizeof(nums[0]) -> gets the dim (in bytes) of one element of the array
    int n = sizeof(nums)/sizeof(nums[0]); 
    int index = binary_search_recursive(nums, target, 0, n-1);

    if (index != 0) printf("element = %d found at index = %d", target, index);
    else printf("element = %d not found in nums", target);

    return 0;
}