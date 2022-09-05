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
	*(*Lee::Log::Single(__FILE__,__LINE__,Level::TYPE))()

namespace Lee{
class OutputStream{
public:
	using ptr = std::shared_ptr<OutputStream>;
	OutputStream(const char*file,int line,Level level):file(file),line(line),m_level(level){
	}
	OutputStream(const OutputStream&)=delete;
	template<typename... Args>
	void operator<<(Args... args){
		NormalLog();
		m_ss << " FILE:"<< file<< " Line:["<< line <<"] "; 
		(m_ss << ... << args);
		exec();
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
	int line=0;
	Level m_level = Level::INFO;
};
class OutputFileStream:public OutputStream{
public:
	using ptr = std::shared_ptr<OutputFileStream>;
	OutputFileStream(const OutputFileStream&)=delete; 
	OutputFileStream(const char*file,int line,const std::string&path,Level level);
	virtual void exec()  override;
	virtual ~OutputFileStream(){}
private:
	std::string m_logpath;
};
class OutputTerminalStream:public OutputStream{
public:
	using ptr = std::shared_ptr<OutputTerminalStream>;
	OutputTerminalStream(const char*file,int line,Level level);
	OutputTerminalStream(const OutputTerminalStream&)=delete;
	virtual void exec() override;
	virtual ~OutputTerminalStream(){}
	
};


class Log{
	Log()=delete;
	explicit Log(const char*file,int line,Level level,OutPutType type);
public:
	static Log*Single(const char*file,int line,Level level,OutPutType type = OutPutType::File);
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
