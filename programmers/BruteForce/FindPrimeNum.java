// 프로그래머스 완전탐색 소수찾기
import java.io.*;
import java.util.*;

class Solution {
    
    static List<Integer> arr= new ArrayList<>();
    static boolean[] visited = new boolean[7];
    
    public int solution(String numbers) {
        int answer = 0;
        
        for(int i=0;i<numbers.length();i++) {
            dfs(numbers,"",i+1);
        }
        
        for(int i=0;i<arr.size();i++) {
            if(isPrime(arr.get(i)))
                answer++;
        }
            
        return answer;
    }
    
    static void dfs(String str, String temp, int level) {
        if(temp.length()==level){
            int num=Integer.parseInt(temp);
            if(!arr.contains(num)) {
                arr.add(num);
            }
        }
        
        for(int i=0;i<str.length();i++){
            if(visited[i])
                continue;
            visited[i]=true;
            temp+=str.charAt(i);
            dfs(str,temp,level);
            visited[i]=false;
            temp=temp.substring(0,temp.length()-1);
        }
        
    }
    
    static boolean isPrime(int n) {
        if(n<2)
            return false;
        for(int i=2;i*i<=n;i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }
}