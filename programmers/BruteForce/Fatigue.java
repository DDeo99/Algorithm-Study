// 프로그래머스 완전탐색 피로도
import java.util.*;
import java.io.*;

class Solution {
    static List<Boolean> visited=new ArrayList<>();
    static int cnt=0;
    
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        visited.clear();
        visited.addAll(Collections.nCopies(dungeons.length,false));
        
        dfs(dungeons,0,k);
        
        return cnt;
    }
    
    static void dfs(int [][]dungeons, int level,int k) {
        for(int i=0;i<dungeons.length;i++){
            if(visited.get(i))
                continue;
            if(dungeons[i][0]>k)
                continue;
            
            visited.set(i,true);
            dfs(dungeons,level+1,k-dungeons[i][1]);
            visited.set(i,false);
        }
        cnt=Math.max(cnt,level);
    }
}