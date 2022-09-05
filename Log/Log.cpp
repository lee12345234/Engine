/*********************************************************************
 * Author           : Leeyingtai
 * Email            : lyt626145245@outlook.com
 * Last modified    : 2022-09-06 03:04
 * Filename         : Log.cpp
 * Description      : 
 * ******************************************************************/
#include "Log.h"
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <execinfo.h>
#include <fcntl.h>
#include <string.h>
namespace Lee{
Log*Log::Single(const char*file,int line,Level level,OutPutType type){
	return new Log(file,line,level,type);

}

Log::Log(const char*file,int line,Level level,OutPutType type){
	time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);
	m_file += m_path;
	m_file += std::to_string(p->tm_year+1900);
	if((p->tm_mon+1)<10)
		m_file +="0";	
	m_file += std::to_string(p->tm_mon+1);
	if((p->tm_mday)<10)
		m_file +="0";	
	m_file += std::to_string(p->tm_mday);
	if((p->tm_hour)<10)
		m_file +="0";	
	m_file += std::to_string(p->tm_hour);
	if((p->tm_min)<10)
		m_file +="0";	
	m_file += std::to_string(p->tm_min);
	if((p->tm_sec)<10)
		m_file +="0";	
	m_file += std::to_string(p->tm_sec);
	switch(type){
		case OutPutType::Terminal:{
			auto ptr = std::make_shared<OutputTerminalStream>(file,line,level);
			m_stream = std::static_pointer_cast<OutputStream>(ptr);	
		}break;
		case OutPutType::File:{
			m_stream = std::static_pointer_cast<OutputStream>(std::make_shared<OutputFileStream>(file,line,m_file,level));
		}break;
	};
		

}
OutputStream::ptr& Log::operator()(){
	
	return m_stream;
}
void Log::SetPath(const std::string&path){
	m_path = path;
	#ifdef __LINUX__
	int ret = access(path.c_str(),F_OK);
	if(!ret){//if directory not exit
		ret = mkdir(path.c_str(),S_IRWXU);
		if(!ret){
			std::cout<<strerror(errno)<<std::endl;
		}
	}
	#endif
}

std::string Log::GetLogPath(){

	return m_path;
}


std::string OutputStream::GetAdrress(){
	void*array[5];
	size_t size;
	size = backtrace(array,5);
	char**msg = backtrace_symbols(array,size);
	std::string tmp = std::string(msg[size-1]);
	auto index_start = tmp.find_last_of('(');
	auto index_end = tmp.find_last_of(')');
	auto functionAdress = tmp.substr(index_start,index_end);//function address
	return functionAdress;
}



std::string OutputStream::GetLevel(Level level){
	switch(level){
		case Level::DEBUG:{
			return std::string("DEBUG");
		};
		case Level::INFO:{
			return std::string("INFO");
		};
		case Level::WARNING:{
			return std::string("WARNING");
		};
		case Level::ERROR:{
			return std::string("ERROR");
		};
		case Level::CRITICAL:{
			return std::string("CRITICAL");
		};
		
		default :{
			return "no level";
		};	
	};

}
std::stringstream&OutputStream::GetStream(){

	return m_ss;
}

void OutputStream::NormalLog(){
	time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);
	m_ss<< p->tm_year+1900  <<"-"
		<< p->tm_mon+1      <<"-"
		<< p->tm_mday       <<"."
		<< p->tm_hour       <<"." 
		<< p->tm_min        <<"."
		<< p->tm_sec        <<" "
		<< GetLevel(m_level)<<" ";
	auto address = GetAdrress();
	m_ss<<address;
}
OutputFileStream::OutputFileStream(const char*file,int line,const std::string&path,Level level):OutputStream(file,line,level),m_logpath(path){
		

}

void OutputFileStream::exec(){
	std::fstream ofs;
	size_t index = m_logpath.find_last_of('/');
	auto tmp = m_logpath.substr(0,index);
	int ret = access(tmp.c_str(),F_OK);
	if(ret == -1){
		ret = mkdir(tmp.c_str(),S_IRWXU);
		if(ret == -1){
		}	
	}
	ret = access(m_logpath.c_str(),F_OK);
	if(ret == -1){
		ret = creat(m_logpath.c_str(),S_IRUSR | S_IWUSR);
	}
	ofs.open(m_logpath.c_str(),std::ios::out | std::ios::app);
	std::stringstream& stream = GetStream();
	ofs<<stream.str()<<"\n";
	ofs.close();
}

OutputTerminalStream::OutputTerminalStream(const char*file,int line,Level level):OutputStream(file,line,level){
	

}

void OutputTerminalStream::exec(){
	
	std::stringstream& stream = GetStream();
	std::cout<<stream.str()<<std::endl;

}

}
