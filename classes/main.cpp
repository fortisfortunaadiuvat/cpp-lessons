#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class temp{
public:
    double minimum,maximum;

    temp(double min=0.0,double max=0.0) : minimum(min) , maximum(max){}

    void write_file(std::ostream & os){
        os.write((char*) &minimum , sizeof(double));
        os.write((char*) &maximum , sizeof(double));
    }

    void read(std::istream & is){
        is.read((char*)&minimum, sizeof(double));
        is.read((char*)&maximum, sizeof(double));
    }
};

void open_close_file(){
    std::ofstream ofile;
    std::ifstream ifile;
    std::fstream iofile;

    ofile.open("file1.txt");
    ifile.open("file1.txt");
    iofile.open("file1.txt");

    if (ofile.is_open()){
        ofile << "first line" << std::endl;
        ofile << "second line" << std::endl;
    }else{
        std::cerr << "file1.data can not open!" << std::endl;
    }

    ofile.close();
    ifile.close();
    iofile.close();
}

void read_file(){
    std::ifstream  ifile;

    ifile.open("file1.txt");

    if (ifile.is_open()){
        std::string line;
        while (std::getline(ifile,line)){
            std::cout << line << std::endl;
        }
    }else{
        std::cerr << "file1.data can not open!" << std::endl;
    }
}

int main() {

    open_close_file();

    read_file();

    stringstream stream;

    stream.str("hakan 23 21");

    string name;
    int age;
    int number;

    stream >> name >> age >> number ;

    std::cout << "name: " << name << std::endl;
    std::cout << "age : " << age  << std::endl;
    std::cout << "number : " << number  << std::endl;

    return 0;
}
