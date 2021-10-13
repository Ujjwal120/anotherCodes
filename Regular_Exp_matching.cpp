bool isMatch(string &s, string &p) {
    int n = s.length();
    int m = p.length();
    
    vector<vector<bool>> table(n+1,vector<bool>(m+1,false));
    
    table[0][0]=true;
    
    for(int i=1;i<=m;++i){
        if(p[i-1]=='*'){
            table[0][i]=table[0][i-2];
        }
    }
    
    for(int i=1;i<=n;++i){
        
        for(int j=1;j<=m;++j){
            
            //if the char is same or it is '.' then
            //we have to ignore this characters and check the previous 
            //subProblem  table [i-1][j-1] (true or false);
            if(s[i-1]==p[j-1] || p[j-1]=='.'){
                
                table[i][j] = table[i-1][j-1];
            }
            
            else if(p[j-1]=='*'){
                
                //case 1 : ignore the character
                //take no character (a*) take no "a"
                if(table[i][j-2]==true){     
                    table[i][j]=true;     
                } 
                
                //case 2 : check if privious letter to * is same for
                //pattern and target string or "."
                //if so table[i][j] takes the value above it
                //since we can take as many character we want
                else if(s[i-1]==p[j-2] || p[j-2]=='.'){
                    
                    table[i][j] = table[i-1][j];
                }
            }
            else{
                table[i][j] = false;
            }
        }
    }
    
    return table[n][m];
    
}