/*Question:

HackerLand University has the following grading policy:

    Every student receives a 

in the inclusive range from to
.
Any
less than

    is a failing grade.

Sam is a professor at the university and likes to round each student's

according to these rules:

    If the difference between the 

and the next multiple of is less than , round up to the next multiple of
.
If the value of
is less than , no rounding occurs as the result will still be a failing grade.

*/

//Solution

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    auto result = grades;
    for(int i = 0; i < grades.size(); i++){
        if(grades[i] >= 38 ){
            int rem = grades[i]%5;
            if(rem > 2){
               result[i] = grades[i] + (5 - rem); 
            }
        }
    }
    
    return result;
}
