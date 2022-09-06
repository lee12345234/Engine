/*********************************************************************
 * Author           : Leeyingtai
 * Email            : lyt626145245@outlook.com
 * Last modified    : 2022-09-06 03:05
 * Filename         : Log.h
 * Description      : 
 * ******************************************************************/
#pragma once
#include <fstream>
#include "Loglevel.h"
#include <sstream>
#include <string>
#include <utility>
#include <memory>
#include <iostream>
#define LOG(TYPE) \
	*(*Lee::Log::Single(__FUNCTION__,__FILE__,__LINE__,Level::TYPE))()

namespace Lee{
class OutputStream{
public:
	using ptr = std::shared_ptr<OutputStream>;
	OutputStream(const char*function,const char*file,int line,Level level):file(file),function(function),line(line),m_level(level){
	}
	OutputStream(const OutputStream&)=delete;
	template<typename... Args>
	std::stringstream&operator<<(Args... args){
		NormalLog();
		m_ss <<" Function:"<< function <<" FILE:"<< file<< " Line:["<< line <<"] "; 
		(m_ss << ... << args);
		exec();
		return m_ss;
	}
	virtual void NormalLog();//init log format
	virtual void exec() = 0;//exec log
	virtual ~OutputStream(){}
	std::stringstream&GetStream();
private:
	std::string GetAdrress();
	std::string GetLevel(Level level);
	std::stringstream m_ss;
	const char*file;
	const char*function;
	int line=0;
	Level m_level = Level::INFO;
};
class OutputFileStream:public OutputStream{
public:
	using ptr = std::shared_ptr<OutputFileStream>;
	OutputFileStream(const OutputFileStream&)=delete; 
	OutputFileStream(const char*function,const char*file,int line,const std::string&path,Level level);
	virtual void exec()  override;
	virtual ~OutputFileStream(){}
private:
	std::string m_logpath;
};
class OutputTerminalStream:public OutputStream{
public:
	using ptr = std::shared_ptr<OutputTerminalStream>;
	OutputTerminalStream(const char* function,const char*file,int line,Level level);
	OutputTerminalStream(const OutputTerminalStream&)=delete;
	virtual void exec() override;
	virtual ~OutputTerminalStream(){}
	
};


class Log{
	Log()=delete;
	explicit Log(const char*function,const char*file,int line,Level level,OutPutType type);
public:
	static Log*Single(const char*function,const char*file,int line,Level level,OutPutType type = OutPutType::File);
	OutputStream::ptr&operator()();	
	void SetPath(const std::string&path);
	std::string GetLogPath();
private:
	std::string m_path = "/home/lee/Log/";
	std::string m_file;
	OutputStream::ptr m_stream;
	//int line = 0;
	//char*file=nullptr;
	
};
}
