#include <bits/stdc++.h>
using namespace std;

class EventManager {
public:
    unordered_map<int, int> mp; 
    set<pair<int, int>> st; // { -priority, eventId }

    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            int id = e[0], pr = e[1];
            mp[id] = pr;
            st.insert({-pr, id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (mp.find(eventId) == mp.end()) return;

        int oldPriority = mp[eventId];

        // remove old entry
        st.erase({-oldPriority, eventId});

        // insert new entry
        mp[eventId] = newPriority;
        st.insert({-newPriority, eventId});
    }
    
    int pollHighest() {
        if (st.empty()) return -1;

        auto it = st.begin();
        int eventId = it->second;

        st.erase(it);
        mp.erase(eventId);

        return eventId;
    }
};
