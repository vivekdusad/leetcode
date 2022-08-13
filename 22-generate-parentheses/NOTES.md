```
void helper(string s,int openLeft,int closedLeft,vector<string> &ans,stack<char> &st){
if(closedLeft==0){
ans.push_back(s);
return;
}
if(openLeft==0){
st.pop();
return helper(s+')',openLeft,closedLeft-1,ans,st);
}
if(st.empty() and openLeft>0){
st.push('(');
return helper(s+'(',openLeft-1,closedLeft,ans,st);
}else{
//we can try both the ways
if(openLeft>0){
st.push('(');
helper(s+'(',openLeft-1,closedLeft,ans,st);
st.pop();
}
st.pop();
helper(s+')',openLeft,closedLeft-1,ans,st);
}
}
```
​