class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v ;
        while(head){
            v.push_back(head->val);
            head = head->next ;
        }
        int n = v.size();
        vector<int>ngn(n) ;
        ngn[n-1] = 0 ;
        stack<int>st ;
        st.push(v[n-1]) ;
        for(int i = n-2 ; i>=0 ; i--){
            while(st.size()!=0 && st.top()<=v[i]) st.pop();
            if(st.size()==0) ngn[i]=0 ;
            else ngn[i]=st.top();
            st.push(v[i]) ;
        }
        return ngn ;
    }
};