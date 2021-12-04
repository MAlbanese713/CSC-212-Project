#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int hash(std::string str);
std::vector<int> RabinKarp(std::string str, std::string pat);
std::string openFile(std::string filename);

int main(int argc, char* argv[]){

    //The string you want to search for the pattern
    std::string str = "";
    //The pattern you are searching for
    std::string pat = "";


    if(argc < 3){
        std::cout << "Usage: ./Rabin-Karp <string> <pattern> or ./Rabin-Karp file <input filename> <pattern>" << std::endl;
        return -1;
    }

    else if(argc == 3){
        str = argv[1];
        pat = argv[2];}

    else if(argc == 4){
        str = openFile(argv[2]);
        pat = argv[3];
    }


    std::vector<int> result = RabinKarp(str,pat);

    for(int i = 0; i < result.size(); i++){
        std::cout << "\"" << pat << "\" found at position " << result.at(i) << std::endl;
    }

    return 0;
}


std::vector<int> RabinKarp(std::string str, std::string pat){

    std::vector<int> finds;
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

        //Debug Statement
        //std::cout << "Hash("<< str.substr(i, m)<<")"  << h_str << std::endl;

        //If both hashes are equal, then check for similarity
        if(h_pat == h_str){
            //If all letters are the same, return position.
            if(str.substr(i, m) == pat){
                finds.push_back(i);
            }
        }
    }

    return finds;
}


//ONly used for initialization
int hash(std::string str){
    int hash = 0;

    for(int i = 0; i < str.length(); i++){
        hash += (int)str[i];
    }



    return hash;
}

std::string openFile(std::string filename){
    std::ifstream source;
    source.open(filename);


    if(source.is_open()){
        std::string full;
        std::string line;
        while(getline(source, line)){
                full += line;
        source.close();
    }
    return full;
}
return "open file failed";
}