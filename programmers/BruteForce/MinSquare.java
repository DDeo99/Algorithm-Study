
// 프로그래머스 완전탐색 최소직사각형
class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int ans[]={-1,-1};
        
        for(int i=0;i<sizes.length;i++)
        {
            int M=Math.max(sizes[i][0],sizes[i][1]);
            int m=Math.min(sizes[i][0],sizes[i][1]);
            
            if(M>ans[0])
                ans[0]=M;
            if(m>ans[1])
                ans[1]=m;
        }
        answer=ans[0]*ans[1];
        
        return answer;
    }
}