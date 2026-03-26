class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer = "";
        char tmp;
        for(int i=0 ; i< my_string.length() ; i++){
            tmp = my_string.charAt(i);
            
            if(i >= s && i < s + overwrite_string.length()){
                tmp = overwrite_string.charAt(i - s);
            }
            answer += tmp;
        }
        
        return answer;
    }
}