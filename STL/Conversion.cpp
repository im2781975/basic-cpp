#include <bits/stdc++.h>
using namespace std;
int prec(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 0;
    }
    return 1;
}
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    string ans=" ";

    for(int i=0;i<s.size();i++)
    {
        char now = s[i];
        if(now >='a' && now <= 'z')
        {
            ans += now;
        }
        else{
            while(st.size() && prec(st.top()) >= prec(now)  )
            {
                ans += st.top();
                st.pop();
                // If the current character is an operator, it enters the else block. It then checks the precedence of the operator with those already in the stack (st).
                //It keeps popping operators from the stack and appending them to the postfix expression (ans) as long as the stack is not empty and the precedence of the operator at the top of the stack is greater than or equal to the precedence of the current operator (now).

                //After this, the current operator (now) is pushed onto the stack.
            }
            st.push(now);
        }
    }
    while(st.size())
    {
        ans += st.top();
        st.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
