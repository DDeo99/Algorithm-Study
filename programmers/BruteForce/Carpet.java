// 프로그래머스 완전탐색 카펫
import java.io.*;
import java.util.*;

class Solution {
    public List<Integer> solution(int brown, int yellow) {
        List<Integer> answer = new ArrayList<>();
        
        int totalNum=brown+yellow;
        
        for(int i=3;i<totalNum;i++){
            int a=i;
            
            if(totalNum%a!=0)
                continue;
            
            int b=totalNum/a;
            
            if((b-2)*(a-2)==yellow) {
                answer.add(b);
                answer.add(a);
                break;
            }
                
        }
        
        return answer;
    }
}