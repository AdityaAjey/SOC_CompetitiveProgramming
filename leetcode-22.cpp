class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> gen;
        if(n==0) return gen;
        if(n==1){
            gen.push_back("()");
            return gen;
        }
        if(n==2){
            gen.push_back("()()");
            gen.push_back("(())");
            return gen;
        }
        for(int i=1;i<n+1;i++){
           
           if(i<n && i>1){
            vector<string> gen1=generateParenthesis(i-1);
            vector<string> gen2=generateParenthesis(n-i);
            for(string x:gen1){
                for(string y:gen2){
                    
                    gen.push_back("("+x+")"+y); // yha problem aa rhi thi  x is a string i wanted to concatenate ( before and ) after x. i did '(' + ')' which caused an error as they are char when in ''. So to add them to string literal I make them string by 
                    // enclosing them in "".
                }
            }
           }
           if(i==n){
             vector<string> gen1=generateParenthesis(i-1);
             for(string x:gen1){
                 gen.push_back('('+x+')');
             }
           }
           if(i==1){
            vector<string> gen1=generateParenthesis(n-1);
             for(string x:gen1){
                 gen.push_back("()"+x);
             }
           }
        }
        return gen;
    }
};

