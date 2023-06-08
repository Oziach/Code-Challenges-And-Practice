/*Question:

Given a time in -hour AM/PM format, convert it to military (24-hour) time.

*/

//Solution
string timeConversion(string s) {
    
    int hours = stoi(s.substr(0,2));
    string sN = s.substr(8,9);
    
    string sConverted = s;
    sConverted.erase(8, 2); 
     
    if(sN == "AM" && hours == 12){ //if between 12AM and 1AM
        sConverted.replace(0, 2, "00");
    }
    
    else if(sN == "PM" && hours != 12){ //if after 1AM except 12 PM
        hours += 12;
        string sHours = to_string(hours);
        
        sConverted.replace(0, 2, sHours);
        
    }
    
    //if 12PM, no changes
    
    return sConverted;
}

