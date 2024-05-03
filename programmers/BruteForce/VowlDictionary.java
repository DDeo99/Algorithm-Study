// 프로그래머스 완전탐색 모음사전
import java.util.*;

class Solution {
    
    static String[] words={"A","E","I","O","U"};
    static int idx=0;
    static int answer = 0;
    
    public int solution(String word) {
        
        dfs(word,"");
        
        return answer;
    }
    
    static void dfs(String word, String temp){
        if(temp.length()>5)
            return;
        
        if(word.equals(temp)){
            answer=idx;
            return;
        }
        
        idx++;
        
        for(int i=0;i<words.length;i++){
            dfs(word,temp+words[i]);
        }
    }
}

/*
class Solution {
    static List<String> list;
    static String[] words={"A","E","I","O","U"};
    
    public int solution(String word) {
        int answer = 0;
        
        list=new ArrayList<>();
        
        for(int i=0;i<words.length;i++) {
            dfs(String.valueOf(words[i]));
        }
        
        int size=list.size();
        
        for(int i=0;i<size;i++){
            if(list.get(i).equals(word)) {
                answer=i+1;
                break;
            }
        }
        
        return answer;
    }
    
    static void dfs(String temp) {
       if(temp.length()>5)
           return;
        if(!list.contains(temp))
            list.add(temp);
        for(int i=0;i<words.length;i++) {
            dfs(temp+words[i]);
        }
    }
}
*/