#include string
#include vector
#include iostream

using namespace std;

vectorint solution(vectorint lottos, vectorint win_nums) {
    int zeroCnt = 0, hitCnt = 0;
    vectorint rank = {6, 6, 5, 4, 3, 2, 1};
    vectorint answer;
    vectorbool winCheck(46, false);
    
    for(int i = 0; i  win_nums.size(); i++)
        winCheck[win_nums[i]] = true;
    
    for(int i = 0; i  lottos.size(); i++)
        if(lottos[i] == 0) zeroCnt++;
    
    for(int i = 0; i  win_nums.size(); i++)
        if(winCheck[lottos[i]]) hitCnt++;
    
    answer.push_back(rank[hitCnt + zeroCnt]);
    answer.push_back(rank[hitCnt]);
    
    return answer;
}