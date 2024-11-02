#include <iostream>
#include <cstring>
#include <list>
#include <cstdio>
#include <io.h>
#include <sstream>
#include <filesystem>
#ifdef _WIN32
#include <windows.h>
#endif
#define SPLIT "----------"
using namespace std;
namespace fs = std::filesystem;
list<string> argv;

template <typename T>  
T getElementAtIndex(const std::list<T>& lst, size_t index) {  
	if (lst.empty() || index >= lst.size()) {  
		throw std::out_of_range("Index out of range.");  
	}
	auto it = lst.begin();  
	std::advance(it, index);  
	return *it;  
} 

void listFilesRecursively(const fs::path& directory, std::string& result) {  
	if (fs::exists(directory) && fs::is_directory(directory)) {  
		for (const auto& entry : fs::directory_iterator(directory)) {  
			// 添加文件或文件夹路径到结果中，用双引号包裹  
			result += "\"" + entry.path().string() + "\" ";  
			
			// 如果是目录，则递归调用  
			if (fs::is_directory(entry)) {  
				listFilesRecursively(entry.path(), result);  
			}  
		}  
	} else {  
		std::cerr << "路径不存在或不是一个目录：" << directory << std::endl;  
	}  
}  


int init() {
#ifdef _WIN32
	char absPath[4096] = {0};
	_fullpath(absPath, "MyGui", 4096);
	strcat(absPath,"\\");
#else
	char absPath[40960] = {0};
	realpath("MyGui", absPath);
	strcat(absPath,"/");
#endif
	if(_access(absPath, 0) != -1){
		cout << "You may have inited MyGui, if you want to init again, please delete floder " << absPath;
		return 1;
	}
	cout << "Checking Git and MingW... \n";
	if (system("git --version > nul") != 0) {  
		cerr << "Git is not installed, cannot continue." << std::endl;
		return 1;
	}
	if (system("g++ --version > nul") != 0) {  
		cerr << "MingW is not installed, cannot continue." << std::endl;
		return 1;
	}
	cout << "Cloning Code...\n" << SPLIT << "\n";
	if(system("git clone https://github.com/lh11117/MyGui.git") != 0) {
		cerr << "Cannot Clone Code!";
		return 1;
	}
	cout << SPLIT << endl;
	cout << "Building..."<<endl;
	ostringstream os;
	os << "g++ ";
	string output;
	listFilesRecursively(fs::path(string(absPath)+"src"),output);
	os << output;
	os << " -shared -o lib.lib -static -I\"MyGui/include\" -std=c++20 -DUNICODE -lgdi32";
	string cmd = os.str();
	cout << "Use: " << cmd << endl << endl;
	return system(cmd.c_str());;
}

int main(int argc,char**args){
	system("");
	for(int i=0;i<argc;i++){
		argv.push_back(string(args[i]));
	}
	if (argc < 2) {
		cerr << "Need help?\nType: \""<<argv.front()<<"\" --help";
		return 0;
	}
	if(argc >=2 && getElementAtIndex(argv, 1) == "--help"){
		cout << "Hello World";
		return 0;
	}
	if(argc >=2 && getElementAtIndex(argv, 1) == "--init"){
		int r = init();
		cout << endl;
		if (r==0){
			cout << "Init sucessfully!";
		} else {
			cerr << "Cannot Init!";
		}
		return r;
	}
}
