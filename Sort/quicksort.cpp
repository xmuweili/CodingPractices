#include <iostream>
#include <vector>
using namespace std; 

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Lprint(std::vector<int> nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
}

void QuickSort(int begin, int end, std::vector<int>& nums) {
	if(begin >= end) return;
	int p = nums[begin];
	int l = begin+1;
	int r = end;
	while(l <= r) {
		if(nums[l] >= p && nums[r] < p)
			swap(nums[l++], nums[r--]);
		if(nums[l] < p) l++;
		if(nums[r] >= p ) r--;
	}
	swap(nums[r], nums[begin]);
	QuickSort(begin, r-1, nums);
	QuickSort(r+1, end, nums);
}

int main(int argc, char* argv[]) {
	int a[13] = {2,3,4,5,1,6,2, 2, 1, 1, 1, 1,1};
	std::vector<int> num(a, a+13);	
	QuickSort(0, 12, num);
	Lprint(num);
	return -1;
}