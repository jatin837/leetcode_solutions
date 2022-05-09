class Solution {
public:
    string res(string a,string b) {
        int i=a.size()-1;
        string ans="";
        char carry= '0';
        while(i>=0)
        {
            int x = a[i] - '0';
            int y = b[i] - '0';
            int z = carry - '0';
            if(x+y+z==3)
            {
                ans+="1";
                carry='1';
            }
            else if(x+y+z==2)
            {
                ans+="0";
                carry='1';
            }
            else if(x+y+z==1)
            {
                ans+="1";
                carry='0';
            }
            else if(x+y+z==0)
            {
                ans+="0";
                carry='0';
            }
            i--;
        }
        if(carry=='1')
            ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string addBinary(string a, string b) 
    {
        if(a.size()!=b.size())
        {
            if(a.size()>b.size())
            {
                int n=a.size()-b.size();
                for(int i=0;i<n;i++)
                    b = "0" + b;
            }
            else
            {
                int n=b.size()-a.size();
                for(int i=0;i<n;i++)
                    a = "0" + a;
            }
        }
        string ans = res(a,b);
        return ans;
    }
};