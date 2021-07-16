#include <iostream>
#include <map>

int main(){
    int n, q, pos;
    std::map<std::string,std::string> m;
    std::string path, line;
    std::cin >> n >> q;
    std::cin.ignore();

    while(n--){
        std::string tag;
        getline(std::cin,line);

        if(line[0]=='<' && line[1]!='/' && line[line.size()-1]=='>'){
            line=line.substr(1,line.size()-2);
            
            if(line.find(' ')!=-1){
                pos=line.find(' ');
                tag=line.substr(0,pos);
                line=line.substr(pos);
            }else{
                tag=line;
            }

            if(path.size()!=0){
                path+='.'+tag;
            }else{
                path=tag;
            }

            while(line.find(" = ")!=-1){
                std::string atr, value;
                line=line.substr(1);

                pos=line.find(" = ");
                atr=line.substr(0,pos);
                line=line.substr(pos+4);

                pos=line.find("\"");
                value=line.substr(0,pos);
                line=line.substr(pos+1);

                std::string key=path+'~'+atr;
                m[key]=value;
            }
            
        }else if(line[1]=='/'){
            line=line.substr(2,line.size()-3);
            tag=line;
            if(path.find('.'+tag)!=-1){
                pos=path.find('.'+tag);
                path=path.substr(0,pos);
            }else{
                path="";
            }
        }
    }

    while(q--){
        getline(std::cin,line);
        if(m.find(line)!=m.end()){
            std::cout << m[line] << std::endl;
        }else{
            std::cout << "Not Found!\n";
        }
    }

    return 0;
}
