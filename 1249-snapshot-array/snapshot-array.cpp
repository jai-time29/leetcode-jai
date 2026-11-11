class SnapshotArray {
    int curr_snap_id=0;
    vector<vector<pair<int,int>>>history;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for(int i=0;i<length;i++){
            history[i].push_back({0,0});// at 0 snapshot we add 0
        }
    }
    
    void set(int index, int val) {
        if(!history.empty()&& history[index].back().first==curr_snap_id){
            history[index].back().second=val;
        }else{
            history[index].push_back({curr_snap_id,val});
        }
    }
    
    int snap() {
      
        
        return curr_snap_id++;

    }
    
    int get(int index, int snap_id) {
        const auto&records = history[index];
        auto it = upper_bound(records.begin(),records.end(),snap_id,
        [](int target_snap,const pair<int,int>&entry){
            return target_snap < entry.first;
        });
        return std::prev(it)->second;
    }
};



// #include <vector>
// #include <algorithm>

// class SnapshotArray {
//     // History for each index: vector of pairs {snap_id, value}
//     std::vector<std::vector<std::pair<int, int>>> history;
//     int curr_snap_id = 0;

// public:
//     SnapshotArray(int length) {
//         history.resize(length);
//         for (int i = 0; i < length; ++i) {
//             history[i].push_back({0, 0}); // Initial value is 0 at snap_id 0
//         }
//     }
    
//     void set(int index, int val) {
//         // If an update already exists for the current snapshot, overwrite it
//         if (!history[index].empty() && history[index].back().first == curr_snap_id) {
//             history[index].back().second = val;
//         } else {
//             history[index].push_back({curr_snap_id, val});
//         }
//     }
    
//     int snap() {
//         return curr_snap_id++;
//     }
    
//     int get(int index, int snap_id) {
//         const auto& records = history[index];
//         // Find the first element with a snap_id strictly greater than requested
//         auto it = std::upper_bound(records.begin(), records.end(), snap_id,
//             [](int target_snap, const std::pair<int, int>& entry) {
//                 return target_snap < entry.first;
//             });
        
//         // Step back one position to get the latest value <= snap_id
//         return std::prev(it)->second;
//     }
// };

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */