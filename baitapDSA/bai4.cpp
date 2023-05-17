#include <bits/stdc++.h>

int n;

int findGreatest(int nums[], int l, int r) {
    if (r < l) return -1;
    
    
    int mid = (l + r) / 2;
        if (mid == 0 || mid == n - 1) return -1;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
    
    int idx = -1;
        if (findGreatest(nums,l, mid - 1) != -1) idx = findGreatest(nums,l, mid - 1);
        if (findGreatest(nums, mid + 1, r) != -1) idx = findGreatest(nums, mid + 1, r);

    return idx;
}

// find(0, 9): 7
//     mid = 4 => not 
//     idx = -1
//     find(0, 3): 3
//         mid = 1 => not
//         idx = -1
//         find(0, 0): -1
//             mid = 0 => return
//         find(2, 3): 3
//             mid = 2 => not
//             idx = -1
//             find(2, 1): -1
//             find(3, 3): 3 
//             idx = 3 return
//         idx = 3 return
//     find(5, 9): 7
//     mid = 7 return 
//     idx = 7

int main() {
    std::cin >> n;
    
    int nums[n];
    for (auto &x : nums) std::cin >> x;

    std::cout << findGreatest(nums, 0, n - 1);

    return 0;
}