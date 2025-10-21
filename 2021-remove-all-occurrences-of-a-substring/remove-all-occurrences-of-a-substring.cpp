class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partlen = int(part.size());

        int i =0;
        while(i<= int(s.size())-partlen){
            if (i + partlen > (int)s.size()) {
                break;
            }
            bool match = true;
            for(int k =0; k<partlen; k++){
                if(s[i+k] != part[k]) {
                    match = false; 
                    break;
                }
            }
            if(match){
                    s.erase(i, partlen);
                    i=0;
            }else{i++;}
        }
        return s;
    }
};