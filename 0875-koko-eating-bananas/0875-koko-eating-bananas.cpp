class Solution {
public:

    long long getHours(const vector<int>& piles, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long hours = getHours(piles, mid);

            if (hours <= h) {
                result = (int)mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};