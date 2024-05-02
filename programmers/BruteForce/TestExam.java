// 프로그래머스 완전탐색 모의고사
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> solution(int[] answers) {
        
        List<Integer> ans=new ArrayList<>();
        
        int a,b,c;
        
        int[] aAns={1,2,3,4,5};
        int[] bAns={2,1,2,3,2,4,2,5};
        int[] cAns={3,3,1,1,2,2,4,4,5,5};
        
        int aCnt=0,bCnt=0,cCnt=0;
        for(int i=0;i<answers.length;i++)
        {
            if(aAns[i%5]==answers[i])
                aCnt++;
            if(bAns[i%8]==answers[i])
                bCnt++;
            if(cAns[i%10]==answers[i])
                cCnt++;
        }
        
        int maxCnt=Math.max(Math.max(aCnt,bCnt),cCnt);
        
        if(aCnt==maxCnt)
            ans.add(1);
        if(bCnt==maxCnt)
            ans.add(2);
        if(cCnt==maxCnt)
            ans.add(3);
        
        return ans;
    }
}