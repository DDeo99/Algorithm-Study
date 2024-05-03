// 프로그래머스 완전탐색 전력망을 둘로 나누기
import java.util.*;

class Solution {
    static ArrayList<Integer>[] graph;
    static int min1;
    static int min2;
    
    public int solution(int n, int[][] wires) {
        int answer = -1;
        
        graph = new ArrayList[n+1];
        min1=101;
        min2=101;
        
        for(int i=1;i<=n;i++) {
            graph[i]=new ArrayList<>();
        }
        
        for(int i=0;i<wires.length;i++) {
            int v1=wires[i][0];
            int v2=wires[i][1];
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
        
        for(int i=0;i<wires.length;i++) {
            int v1=wires[i][0];
            int v2=wires[i][1];
            
            boolean[] visited = new boolean[n+1];
            
            graph[v1].remove(Integer.valueOf(v2));
            graph[v2].remove(Integer.valueOf(v1));
            
            int cnt=dfs(1,visited);
            int diff=Math.abs(cnt-(n-cnt));
            min1=Math.min(min1,diff);
            
            int cnt2=bfs(1,n);
            int diff2=Math.abs(cnt2-(n-cnt2));
            min2=Math.min(min2,diff2);
            
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
        
        return min1;
    }
    
    static int dfs(int v, boolean[] visited) {
        visited[v]=true;
        int cnt=1;
        
        for(int next:graph[v]) {
            if(!visited[next]) {
                cnt+=dfs(next,visited);
            }
        }
        return cnt;
    }
    
    static int bfs(int v, int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] check = new boolean[n+1];
        int cnt=0;
        
        q.add(v);
        check[v]=true;
        while(!q.isEmpty()) {
            int now=q.poll();
            cnt++;
            for(int next:graph[now]) {
                if(!check[next]) {
                    q.add(next);
                    check[next]=true;
                }
            } 
        }
        return cnt;
    }
}