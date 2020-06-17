class Solution {
public:
    
    int toNum(string s){
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(s[i]-'0')*pow(10,n-1-i);
        }
        return ans;
    }
    
    bool check4(string s){
        int n = s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                if(t=="" || t.size()>3)
                    return false;
                int x = toNum(t);
                if(t.size()>1 && t[0]=='0')
                    return false;
                if(x>255)
                    return false;
                t="";
            }
            else if(s[i]>='0' && s[i]<='9')
                t+=s[i];
            else
                return false;
        }
        if(t=="")
            return false;
        int x = toNum(t);
        int n1 = log10(x)+1;
        int n2 = t.size();
        if(n1!=n2)
            return false;
        if(x>255)
            return false;
        return true;
    }
    
    bool check6(string s){
        int n = s.size();
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]==':'){
                if(t=="")
                    return false;
                if(t.size()>4)
                    return false;
                for(char x:t){
                    if(!isxdigit(x))
                        return false;
                }
                t="";
            }
            else
                t+=s[i];
        }
        if(t=="" || t.size()>4)
            return false;
        for(char x:t){
            if(!isxdigit(x))
                return false;
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        int dot=0,colon=0;
        for(char x:IP){
            if(x=='.')
                dot++;
            else if(x==':')
                colon++;
        }
        if(dot==3 && check4(IP))
            return "IPv4";
        if(colon==7 && check6(IP))
            return "IPv6";
        return "Neither";
    }
};