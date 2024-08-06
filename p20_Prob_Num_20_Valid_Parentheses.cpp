class Solution {
public:
    bool isValid(string s) 
    {
        // initializing character stack
        stack<char> st;

        // making for loop till the length of string
        for (int i=0; i<s.length(); i++)
        {
            char ch=s[i];

            // pushing only if the ch is equal to (, [, or {
            if ((ch=='(')||(ch=='[')||(ch=='{'))
            {
                st.push(ch);
            }

            // if the ch is equal to ), ], or } then we matchcase the top character in stack and the ch itself
            else
            {
                // if stack is empty then only we matchcase the top character in stack and the ch itself
                if (!st.empty())
                {
                    char top=st.top();

                    // if match found then we pop
                    if (((ch==')')&&(top=='('))||((ch==']')&&(top=='['))||((ch=='}')&&(top=='{')))
                    {
                        st.pop();
                    }

                    // if match not found then it is false
                    else
                    {
                        return false;
                    }
                }

                // if stack is not empty then it is invalid i.e false
                else
                {
                    return false;
                }
            }
        }

        // if at end stack is empty then experession is valid
        if (st.empty())
        {
            return true;
        }

        // if at end stack is not empty then experession is not valid
        else
        {
            return false;
        }
    }
};