#define pii pair<int, int>
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        vector<pii> v (n);
        for (int i = 0; i < n; i++)
            v[i] = {start[i], end[i]};
        
        sort(v.begin(), v.end(), [](pii a, pii b){
            return a.second < b.second; 
        });
        
        int c = 1;
        int last_meeting_index = 0;
        for (int i = 1; i < n; i++) {
            if (v[i].first > v[last_meeting_index].second)
                last_meeting_index = i, c++;
        }

        return c;
    }
};
