// counting inversions using merge sort
ll ans = 0; // make sure to make ans = 0 at each new testcase since it is global variable

void merge(vector <ll>& final, ll l, ll mid1, ll mid2, ll r){
    vector <ll> temp;
    ll cnt = 0;
    ll left = l, right = mid2;
    
    while((left<=mid1)&&(right <= r)){
        if(final[left] <= final[right]){
            temp.pb(final[left]);
            left++;
            ans += cnt;
        }else{
            temp.pb(final[right]);
            right++;
            cnt++;
        }
        
    }
    
    while(left<=mid1){
        temp.pb(final[left]);
        left++;
        ans += cnt;
    }
    
    while(right <= r){
        temp.pb(final[right]);
        right++;
    }
    
    for(int i = l;i<=r;i++){
        final[i] = temp[i-l];
    }
}

void merge_sort(vector <ll>& final, ll l, ll r){
    if(l >= r){
        return;
    }
    ll mid = l + (r-l)/2;
    merge_sort(final,l,mid);
    merge_sort(final,mid+1,r);
    
    merge(final,l,mid,mid+1,r);
}
