//custom sorting comparator that sorts based on pair.second basis in ascending order
//tc = O(n*logn*(time take for each comparison))
struct cmp{
    // the bool should return true if a is to be placed before b
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second != b.second){
            return a.second < b.second;
        }else return a.first < b.first;
    }
}
