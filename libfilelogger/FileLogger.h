#pragma once

#include <string>
#include <fstream>

#include "ILogger.h"

class FileLogger : public ILogger {
public:
	FileLogger(const std::string& tag);
	FileLogger(FileLogger const&);
	FileLogger(const FileLogger& o, const std::string& prefix);
	void operator=(FileLogger const&) = delete;
	virtual ~FileLogger();

	const std::string& getTag() const override;

	// append output for the next file flush
	void log(const std::string& msg) override;
	void i(const std::string& msg) override;
	void w(const std::string& msg) override;
	void e(const std::string& msg) override;

	// clear previous file content
	void clear();

	template<typename T>
	std::ostream& operator<<(const T& obj) {
		mOfs << mPrefix << obj << std::flush;
		return mOfs;
	}

	std::string d() { return debug; }
	std::string v() { return verbose; }
	std::string i() { return info; }
	std::string w() { return warn; }
	std::string e() { return err; }
	std::string endl() { return normal + '\n'; }

private:
	FileLogger(const std::string& tag, const std::string& prefix);

	const std::string mFolder;
	const std::string mTag;
	const std::string mPrefix;
	const std::string mOutputPath;
	std::ofstream mOfs;

public:


	static const std::string normal;
	static const std::string debug;
	static const std::string verbose;
	static const std::string info;
	static const std::string warn;
	static const std::string err;
};
