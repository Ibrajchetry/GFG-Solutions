class Solution {
  public:
    int leastWeightCapacity(vector<int>& arr, int k) {
        // code here
         if (k > arr.size())
            return -1;

        long long start = 0, end = 0, ans = -1;

        for (int x : arr) {
            start = max(start, (long long)x);
            end += x;
        }

        while (start <= end) {

            long long mid = start + (end - start) / 2;

            long long pages = 0;
            int count = 1;

            for (int x : arr) {
                pages += x;

                if (pages > mid) {
                    count++;
                    pages = x;
                }
            }

            if (count <= k) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return (int)ans;
    }
};