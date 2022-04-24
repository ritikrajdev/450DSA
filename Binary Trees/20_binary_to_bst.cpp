void inorder(vector<int>&arr, int i, vector<int>& inorder_arr) {
	if (i >= arr.size() || arr[i] == -1)
		return;
	
	inorder(arr, 2*i+1, inorder_arr);
	inorder_arr.push_back(arr[i]);
	inorder(arr, 2*i + 2, inorder_arr);
}

int min_swaps_sort_array(vector<int>& arr) {
	vector<pair<int, int>> sorted;
	for (int i = 0; i < arr.size(); i++)
		sorted.push_back({arr[i], i});
	sort(sorted.begin(), sorted.end());
	
	int c = 0;
	
	for (int i = 0; i < sorted.size(); i++) {
		while (sorted[i].second != i) {
			int index = sorted[i].second;
			swap(sorted[i], sorted[index]);
			c++;
		}
	}
	return c;
}

int minimumSwaps(vector<int>&arr, int n) {
	vector<int> inorder_arr;
	inorder(arr, 0, inorder_arr);
	
	return min_swaps_sort_array(inorder_arr);
}
