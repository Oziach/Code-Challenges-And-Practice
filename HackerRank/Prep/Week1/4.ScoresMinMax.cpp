/*Question:

Maria plays college basketball and wants to go pro. 
Each season she maintains a record of her play. She tabulates the number of times she breaks her season record for most points and least points in a game. 
Points scored in the first game establish her record for the season, and she begins counting from there.
Given the scores for a season, determine the number of times Maria breaks her records for most and least points scored during the season.

*/

//Solution
vector<int> breakingRecords(vector<int> scores) {
    int min = scores[0]; int minRecordCount = 0;
    int max = scores[0]; int maxRecordCount = 0;
    for(int i = 1; i < (int)scores.size(); i++){
        if(scores[i] < min){
            min = scores[i];
            minRecordCount++;
        }
        else if(scores[i] > max) {
            max = scores[i];
            maxRecordCount++;
        }
    }
    
    vector<int> count = {maxRecordCount, minRecordCount};
    return count;
}

