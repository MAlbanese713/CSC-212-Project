#include <string>
#include <iostream>

int hash(std::string str);
int RabinKarp(std::string str, std::string pat);

int main(){

    //The string you want to search for the pattern
    std::string str = "jqkwehqkjwehqoiadiojwHellokjqwebqweoqweiqwemc";
    //The pattern you are searching for
    std::string pat = "emc";

    int result = RabinKarp(str,pat);

    if(result != -1){
        std::cout << pat << " found at position " << result;
    }
    else{
        std::cout << pat <<" not found.";
    }
    return 0;
}


int RabinKarp(std::string str, std::string pat){


    //Hashes the pattern for comparison
    int h_pat = hash(pat);


    int m = pat.length();

    //Initializes the hashing on position 0
    int h_str = hash(str.substr(0, m));

    for(int i = 0; i < str.length()-pat.length()+1; i++){
        if(i != 0){
            //Applies a rolling hash, subtracting the left letter, and adding the right letter
            h_str += (int)str[i+m-1];
            h_str -= (int)str[i-1];}
        std::cout << "Hash("<< str.substr(i, m)<<")"  << h_str << std::endl;

        //If both hashes are equal, then check for similarity
        if(h_pat == h_str){
            //If all letters are the same, return position.
            if(str.substr(i, m) == pat){
                return i;
            }
        }
    }
    //If not found, return -1;
    return -1;
}


//ONly used for initialization
int hash(std::string str){
    int hash = 0;

    for(int i = 0; i < str.length(); i++){
        hash += (int)str[i];
    }



    return hash;
}