class Solution {
public:
    long long sum = 0;
    set<pair<int, int>> main; // contains top X frequent element
    set<pair<int, int>> sec;

    void insertInSet(pair<int, int> p , int x) {
        if (main.size() < x || p > *main.begin()) {
            sum += 1LL * p.first * p.second;
            main.insert(p);

            if (main.size() > x) {
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }
    void removeFromSet(pair<int, int> p , int x) {
        if (main.find(p) != main.end()) {
            sum -= 1LL * p.first * p.second;
            main.erase(p);

            if (sec.size() > 0) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                sum += 1LL * largest.first * largest.second;
                main.insert(largest);
            }
        } else {
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        sum = 0;
        int n = nums.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;

        while (j < n) {
            if (mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]} , x);
            }
            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]} , x);

            if (j - i + 1 == k) {
                result.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]} , x);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]} , x);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};